#c-casebook: Intro to C with Beej

A self-directed, introduction to C focused on writing correct, reviewable programs and iterating them through increasingly realistic constraints.

This repo pairs two things:

- Reading track: Beej’s Guide to C (see Readings.txt)
- Build track: a single program called Casebook, evolved across 7 projects (see Project_1.txt to Project_7.txt)

The result is a clean, repeatable progression from “one-file menu program” to a multi-file C project with dynamic memory, persistence, reports, and hardened error handling.

----------------------------------------------------------------
What is Casebook?

Casebook is an iterative CLI program that grows in capability each project. The goal is not feature bloat. The goal is disciplined C fundamentals with clear invariants, safe input, and reliable demos.

Across the projects, Casebook moves through:

- Menu loop and stable flow
- Functions, arrays, and strings
- Struct modeling and file persistence
- Dynamic memory with malloc / realloc / free and ownership rules
- Stronger typing with size_t, enums, and bit flags
- Multi-file organization with headers and a Makefile
- A stability pass that focuses on predictable behavior and robustness

----------------------------------------------------------------
Skills demonstrated

By the end of Project 7, this repo is designed to demonstrate:

- Clean builds with warnings enabled and no warnings emitted
- Defensive input handling for common CLI failure cases
- Data modeling with struct, enum, and bit flags
- File I/O with a documented text format and load/save workflow
- Dynamic memory management with explicit ownership and cleanup
- A project split into compilation units with headers and a Makefile
- Repeatable demo scripts that prove behavior and prevent regressions

----------------------------------------------------------------
Repo layout

At the repo root you will find the course specifications and repeatable demos:

- COURSE_OVERVIEW.txt
- Readings.txt
- Wireframes.txt
- DEMO_SCRIPTS.txt

The runnable code lives under projects/:

projects/
  project-01-casebook/
  project-02-casebook/
  ...
  project-07-casebook/

Working directory rule:

- When reading specs, stay in the repo root.
- When building and running code, cd into the specific project folder.

----------------------------------------------------------------
Build and run

Early projects use a direct gcc command (documented in each project spec and in the demo scripts). Later projects use a Makefile.

Typical workflow:

  cd projects/project-04-casebook
  gcc ...    (early projects)
  or:
  make       (later projects)
  ./casebook

Some later projects include targets for development tooling, such as debug builds and AddressSanitizer. See the project folder Makefile for the exact targets.

----------------------------------------------------------------
Demo scripts

This repo treats demos as a lightweight discipline, not a full test suite.

DEMO_SCRIPTS.txt contains repeatable procedures for each project part, including:

1. Setup (reset runtime data if needed)
2. Build step (gcc or make)
3. Run step (interactive inputs or scripted stdin)
4. Verification (must-see output lines and sanity checks)
5. Persistence checks (Projects 3+)

For line-based UIs, demos can also be executed via stdin redirection:

  ./casebook < tests/demo_input.txt > tests/actual_output.txt

The point is repeatability. If a demo fails, fix the bug, rerun the demo, then commit.

----------------------------------------------------------------
Project milestones

High-level progression of what changes each project:

- Project 1: Program shape (menu loop, flow, input discipline)
- Project 2: Functions + arrays/strings (fixed-capacity storage and invariants)
- Project 3: Structs + persistence (load/save with documented format)
- Project 4: Dynamic memory (growth with realloc, count/capacity invariants)
- Project 5: Types + enums + bit flags + reports (stronger modeling and reporting)
- Project 6: Multi-file + Makefile + configuration hook (headers, targets, env or CLI)
- Project 7: Consolidation and stability (additional reports and robustness pass)

----------------------------------------------------------------
How to review this repo quickly

If you are reviewing this, the fastest path is:

1. Open COURSE_OVERVIEW.txt to understand the structure.
2. Jump to projects/project-07-casebook/ for the final form.
3. Scan the Makefile and module layout.
4. Run the Project 7 demo procedure from DEMO_SCRIPTS.txt.

That workflow is the intended “capstone” demonstration: build cleanly, run predictably, persist data, and generate deterministic reports.

----------------------------------------------------------------
Notes on scope

This course intentionally prioritizes correctness, clarity, and iteration over feature volume. The specs emphasize a PASS bar first, with optional “Strong” improvements when time permits. The outcome is a repo that shows how I approach systems work: tight invariants, careful I/O, explicit memory ownership, and repeatable demonstrations.
