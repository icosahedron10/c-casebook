# Intro to C (Beej’s Guide to C) — Reading Plan Aligned to Casebook Project

This is a personal reading and practice plan designed to prepare for **GIOS** by working through **Beej’s Guide to C Programming** alongside the Casebook project.

---

## Week 1 — Project 1A (Casebook v0: program shape + toolchain)

### Reading
- Ch 1: Introduction (pp. 1–4)
- Ch 2: Hello, World! (pp. 5–10)

### Concepts you should be able to use by week’s end
- Compile and run a C program using `cc`/`gcc` with warnings enabled (`-Wall -Wextra`).
- Explain the role of `main`, return values, and the basic compilation pipeline.
- Write a minimal, well-formed C program with correct includes.
- Understand the difference between source files and binaries.

### Project tie-in
- Project 1, Week A: repo layout + build command + a menu scaffold (no storage yet)

---

## Week 2 — Project 1B (Casebook v0: control flow + basic input)

### Reading
- Ch 3: Variables and Statements (pp. 11–26)

### Concepts you should be able to use by week’s end
- Declare, initialize, and assign variables using appropriate types.
- Use `if/else`, `switch`, `while`, and `for` for control flow.
- Read user input safely using `fgets`.
- Enforce a simple program flow contract (menu loop + clean exit).

### Project tie-in
- Project 1, Week B: implement menu actions as stubs + enforce “program flow contract”

---

## Week 3 — Project 2A (Casebook v1: functions + clean structure)

### Reading
- Ch 4: Functions (pp. 27–31)
- Ch 5: Pointers, basic (pp. 32–39)

### Concepts you should be able to use by week’s end
- Define and call functions with clear inputs and outputs.
- Write correct function prototypes and understand why they are required.
- Distinguish pass-by-value from pass-by-pointer.
- Use pointers to allow functions to modify caller-owned data.

### Project tie-in
- Project 2, Week A: refactor actions into functions + introduce invariants (IDs, valid references)

---

## Week 4 — Project 2B (Casebook v1: arrays + strings + fixed-capacity storage)

### Reading
- Ch 6: Arrays (pp. 40–48)
- Ch 7: Strings (pp. 49–54)

### Concepts you should be able to use by week’s end
- Declare and index arrays safely within bounds.
- Understand array-to-pointer decay when passing arrays to functions.
- Manipulate C strings as null-terminated `char` arrays.
- Use standard string functions (`strlen`, `strcmp`, `strncpy`) safely.

### Project tie-in
- Project 2, Week B: implement fixed-capacity clients/transactions + basic listing

---

## Week 5 — Project 3A (Casebook v2: structs for real records)

### Reading
- Ch 8: Structs (pp. 55–58)

### Concepts you should be able to use by week’s end
- Define `struct` types to model real records.
- Access struct members directly and via pointers.
- Store structs in arrays and pass them to functions.
- Group related data intentionally for clarity and safety.

### Project tie-in
- Project 3, Week A: migrate arrays → struct-based records (still fixed-capacity)

---

## Week 6 — Project 3B (Casebook v2: persistence via file I/O)

### Reading
- Ch 9: File I/O (pp. 59–67)

### Concepts you should be able to use by week’s end
- Open, read, write, and close files using `FILE *`.
- Design and document a simple file format.
- Handle file open/read/write errors defensively.
- Distinguish fixture data from runtime data.

### Project tie-in
- Project 3, Week B: load/save clients and transactions + fixtures vs runtime data policy

---

## Week 7 — Project 4A (Casebook v3: typedef + pointer arithmetic as tools)

### Reading
- Ch 10: typedef (pp. 68–71)
- Ch 11: Pointers II, Arithmetic (pp. 72–80)

### Concepts you should be able to use by week’s end
- Use `typedef` to simplify complex type declarations.
- Perform pointer arithmetic correctly and intentionally.
- Traverse arrays and buffers using pointers.
- Reason about memory layout based on type size.

### Project tie-in
- Project 4, Week A: introduce typedefs + prep storage layer for resizing

---

## Week 8 — Project 4B (Casebook v3: manual memory allocation + ownership)

### Reading
- Ch 12: Manual Memory Allocation (pp. 81–89)
- Ch 13: Scope (pp. 90–93)

### Concepts you should be able to use by week’s end
- Allocate and free memory with `malloc`, `calloc`, `realloc`, and `free`.
- Define clear ownership and lifetime rules for heap memory.
- Avoid memory leaks, double frees, and use-after-free errors.
- Understand scope, lifetime, and storage duration.

### Project tie-in
- Project 4, Week B: replace fixed limits with dynamic arrays + define free/cleanup behavior

---

## Week 9 — Project 5A (Casebook v4: type discipline)

### Reading
- Ch 14: Types II (pp. 94–106)

### Concepts you should be able to use by week’s end
- Choose appropriate numeric types for correctness.
- Understand integer promotion, truncation, and overflow.
- Write deterministic and auditable calculations.
- Recognize undefined vs implementation-defined behavior.

### Project tie-in
- Project 5, Week A: type audit + deterministic reporting calculations

---

## Week 10 — Project 5B (Casebook v4: conversions + enums + bit flags)

### Reading
- Ch 15: Types III (pp. 107–115)
- Ch 16: Types IV (pp. 116–123)
- Ch 22: Enumerated Types (enum) (pp. 184–187)
- Ch 24: Bitwise Operations (pp. 199–200)

### Concepts you should be able to use by week’s end
- Parse numeric input using `strtol` / `strtod`.
- Define and use `enum` types for categories.
- Use bitwise operators for flags and masks.
- Persist enum and flag values safely.

### Project tie-in
- Project 5, Week B: robust numeric parsing + enum categories + flags + persistence defaults

---

## Week 11 — Project 6A (Casebook v5: multifile structure)

### Reading
- Ch 17: Multifile Projects (pp. 124–128)

### Concepts you should be able to use by week’s end
- Split a program into multiple `.c` and `.h` files.
- Use header guards and forward declarations.
- Understand linkage, visibility, and the one-definition rule.
- Build with a Makefile.

### Project tie-in
- Project 6, Week A: split Casebook into modules + add a Makefile baseline

---

## Week 12 — Project 6B (Casebook v5: outside environment + preprocessor)

### Reading
- Ch 18: The Outside Environment (pp. 129–138)
- Ch 19: The C Preprocessor (pp. 139–160)

### Concepts you should be able to use by week’s end
- Access command-line arguments via `argc` / `argv`.
- Read environment variables safely.
- Use preprocessor directives responsibly.
- Support debug and instrumentation builds.

### Project tie-in
- Project 6, Week B: CLI/config + debug/asan targets + preprocessor cleanup

---

## Week 13 — Project 7A (Casebook v6: structs II + strings II for stability)

### Reading
- Ch 20: Structs II (pp. 161–178)
- Ch 21: Characters and Strings II (pp. 179–183)

### Concepts you should be able to use by week’s end
- Design nested and composed structs.
- Handle strings defensively in formatting.
- Harden validation and state transitions.
- Produce stable, testable output.

### Project tie-in
- Project 7, Week A: validation hardening + stable report formatting + fixture-driven checks

---

## Week 14 — Project 7B (Casebook v6: pointers III + final polish)

### Reading
- Ch 23: Pointers III (pp. 188–198)

### Concepts you should be able to use by week’s end
- Use multi-level pointers correctly.
- Implement deletion and compaction patterns.
- Perform a full memory audit.
- Ensure clean shutdown and cleanup.

### Project tie-in
- Project 7, Week B: deletion/refactor patterns + final memory audit + “ship it” polish