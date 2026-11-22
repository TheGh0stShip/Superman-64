import json
import subprocess
import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import generate_decomp_report as report_generator


class DecompReportTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.report = report_generator.build_report()

    def test_production_totals(self):
        measures = self.report["measures"]
        self.assertEqual(self.report["version"], 2)
        self.assertEqual(measures["total_code"], "875680")
        self.assertEqual(measures["matched_code"], "98844")
        self.assertEqual(measures["complete_code"], "98632")
        self.assertEqual(measures["total_functions"], 1056)
        self.assertEqual(measures["matched_functions"], 528)
        self.assertEqual(measures["total_data"], "43344")
        self.assertEqual(measures["matched_data"], "0")
        self.assertEqual(measures["total_units"], 152)
        self.assertEqual(measures["complete_units"], 85)

    def test_units_account_for_every_function_once(self):
        functions = [function for unit in self.report["units"]
                     for function in unit["functions"]]
        self.assertEqual(len(functions), 1056)
        self.assertEqual(len({function["address"] for function in functions}), 1056)
        self.assertEqual(sum(int(function["size"]) for function in functions), 865304)
        code_units = [unit for unit in self.report["units"] if unit["functions"]]
        self.assertEqual(len(code_units), 152)
        self.assertTrue(all(unit["name"] == unit["metadata"]["source_path"]
                            for unit in code_units))
        self.assertTrue(all(unit["name"].startswith("src/")
                            and unit["name"].endswith(".c")
                            for unit in code_units))
        self.assertTrue(all(unit["metadata"]["progress_categories"] == ["cpu_units"]
                            for unit in code_units))
        first_addresses = [int(unit["functions"][0]["address"])
                           for unit in code_units]
        self.assertEqual(first_addresses, sorted(first_addresses))
        self.assertEqual(sum(int(unit["measures"]["total_code"])
                             for unit in code_units), 866788)
        self.assertEqual(sum(int(unit["measures"]["matched_code"])
                             for unit in code_units), 98844)
        self.assertEqual(sum(int(unit["measures"]["complete_code"])
                             for unit in code_units), 35184)
        self.assertEqual(sum(
            int(function["size"]) for function in functions
            if function["fuzzy_match_percent"] == 100.0
        ), 98180)
        self.assertTrue(all(
            unit["measures"]["matched_code"] == unit["measures"]["total_code"]
            and unit["measures"]["complete_code"] == unit["measures"]["total_code"]
            for unit in code_units if unit["metadata"]["complete"]
        ))
        self.assertTrue(all(
            set(function) == {"name", "size", "fuzzy_match_percent", "address", "metadata"}
            for function in functions
        ))
        externally_verified = [
            function for function in functions
            if function["metadata"]["source_path"].startswith("verified/n64dk/")
        ]
        self.assertEqual(len(externally_verified), 271)
        self.assertTrue(all(function["fuzzy_match_percent"] == 100.0
                            for function in externally_verified))
        linked_external = [function for function in externally_verified
                           if function["metadata"]["linked"]]
        self.assertEqual(len(linked_external), 271)
        self.assertEqual(sum(int(function["size"])
                             for function in linked_external), 51728)
        self.assertTrue(all(
            function["metadata"]["link_profile"] == "n64dk-mixed-exact-c"
            for function in linked_external
        ))
        self.assertFalse(any(not function["metadata"]["linked"]
                             for function in externally_verified))

    def test_category_breakdown(self):
        categories = {item["id"]: item for item in self.report["categories"]}
        self.assertEqual(set(categories), {
            "cpu_units", "cpu_tail", "rsp", "data", "graphics", "referenced",
            "unknown", "padding", "metadata",
        })
        self.assertEqual(categories["cpu_units"]["measures"]["total_units"], 152)
        self.assertEqual(categories["cpu_units"]["measures"]["total_code"], "866788")
        self.assertEqual(categories["cpu_tail"]["measures"]["total_code"], "1532")
        self.assertEqual(categories["rsp"]["measures"]["total_code"], "7360")
        self.assertEqual(categories["data"]["measures"]["total_data"], "43344")
        self.assertEqual(categories["data"]["measures"]["matched_data"], "0")
        self.assertEqual(categories["data"]["measures"]["matched_data_percent"], 0.0)
        for name, category in categories.items():
            if name not in {"cpu_units", "cpu_tail", "rsp"}:
                self.assertEqual(category["measures"]["total_code"], "0")
                self.assertGreater(int(category["measures"]["total_data"]), 0)
        accounted = sum(
            int(categories[name]["measures"]["total_code"])
            for name in ("cpu_units", "cpu_tail", "rsp")
        )
        accounted += sum(
            int(category["measures"]["total_data"])
            for name, category in categories.items()
            if name not in {"cpu_units", "cpu_tail", "rsp"}
        )
        self.assertEqual(accounted, 0x800000)
        category_ids = set(categories)
        self.assertTrue(all(
            set(unit["metadata"]["progress_categories"]) <= category_ids
            for unit in self.report["units"]
        ))

    def test_boundary_evidence_and_nonfunction_ledger(self):
        result = subprocess.run(
            [sys.executable, "tools/audit_function_boundaries.py"],
            cwd=ROOT, check=True, capture_output=True, text=True,
        )
        self.assertIn("1056 functions: 865304 bytes", result.stdout)
        self.assertIn("157 gaps: 1516 bytes", result.stdout)

    def test_public_metadata_contract(self):
        metadata = json.loads((ROOT / ".recomp.json").read_text())
        self.assertEqual(metadata["original"]["serial"], "NSPE")
        self.assertEqual(metadata["maintainers"], [{
            "name": "TheGh0stShip",
            "link": "https://github.com/TheGh0stShip",
        }])
        workflow = (ROOT / ".github/workflows/progress.yml").read_text()
        self.assertIn("name: NSPE_report", workflow)

    def test_overlay_evidence_is_bound_without_resident_credit(self):
        profile = json.loads((ROOT / "config/us/linked_profiles.json").read_text())["profiles"][0]
        auxiliary = profile["auxiliary_manifests"]
        self.assertEqual(auxiliary, [{
            "path": "config/us/verified_n64dk_overlays.tsv",
            "sha256": auxiliary[0]["sha256"],
        }])
        manifest = ROOT / auxiliary[0]["path"]
        import hashlib
        self.assertEqual(hashlib.sha256(manifest.read_bytes()).hexdigest(),
                         auxiliary[0]["sha256"])
        rows = [line for line in manifest.read_text().splitlines()
                if line and not line.startswith("#")]
        self.assertEqual(len(rows), 1)
        self.assertIn("func_8026B000", rows[0])
        self.assertEqual(self.report["measures"]["matched_functions"], 528)


if __name__ == "__main__":
    unittest.main()
