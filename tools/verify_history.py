#!/usr/bin/env python3
"""Reject commits that are not owned by the project account."""

from __future__ import annotations

import subprocess

EXPECTED_NAME = "TheGh0stShip"
EXPECTED_EMAIL = "5899914+TheGh0stShip@users.noreply.github.com"


def git(*args: str) -> str:
    return subprocess.check_output(("git", *args), text=True).strip()


def main() -> None:
    roots = git("rev-list", "--max-parents=0", "HEAD").splitlines()
    if len(roots) != 1:
        raise SystemExit(f"history: expected one root commit, found {len(roots)}")

    records = git(
        "log", "--format=%H%x09%an%x09%ae%x09%cn%x09%ce", "HEAD"
    ).splitlines()
    for record in records:
        commit, author, author_email, committer, committer_email = record.split("\t")
        if (author, author_email) != (EXPECTED_NAME, EXPECTED_EMAIL):
            raise SystemExit(f"history: unexpected author on {commit}")
        if (committer, committer_email) != (EXPECTED_NAME, EXPECTED_EMAIL):
            raise SystemExit(f"history: unexpected committer on {commit}")

    print(f"history: verified one root and {len(records)} owned commits")


if __name__ == "__main__":
    main()
