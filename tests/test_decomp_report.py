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
        self.assertEqual(measures["total_code"], "865304")
        self.assertEqual(measures["matched_code"], "15836")
        self.assertEqual(measures["total_functions"], 1050)
        self.assertEqual(measures["matched_functions"], 131)
        self.assertEqual(measures["total_units"], 190)
        self.assertEqual(measures["complete_units"], 102)

    def test_units_account_for_every_function_once(self):
        functions = [function for unit in self.report["units"]
                     for function in unit["functions"]]
        self.assertEqual(len(functions), 1050)
        self.assertEqual(len({function["address"] for function in functions}), 1050)
        self.assertEqual(sum(int(function["size"]) for function in functions), 865304)
        self.assertTrue(all(unit["name"] == unit["metadata"]["source_path"]
                            for unit in self.report["units"]))

    def test_boundary_evidence_and_nonfunction_ledger(self):
        result = subprocess.run(
            [sys.executable, "tools/audit_function_boundaries.py"],
            cwd=ROOT, check=True, capture_output=True, text=True,
        )
        self.assertIn("1050 functions: 865304 bytes", result.stdout)
        self.assertIn("154 gaps: 1432 bytes", result.stdout)

    def test_public_metadata_contract(self):
        metadata = json.loads((ROOT / ".recomp.json").read_text())
        self.assertEqual(metadata["original"]["serial"], "NSPE")
        self.assertEqual(metadata["maintainers"], [{
            "name": "TheGh0stShip",
            "link": "https://github.com/TheGh0stShip",
        }])
        workflow = (ROOT / ".github/workflows/progress.yml").read_text()
        self.assertIn("name: NSPE_report", workflow)


if __name__ == "__main__":
    unittest.main()
