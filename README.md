# C Programming Exercises

> A focused set of C exercises that builds from core language fundamentals to pointers and dynamic memory management.

## Progress at a Glance

| Current scope | Progress | Status |
| :-- | :-- | :-- |
| **Section 1 — Basics** | 5 / 5 exercises | ✅ Complete |
| **Section 2 — Pointers** | 4 / 4 exercises | ✅ Complete |
| **Section 3 — Memory Management** | 3 / 3 exercises | ✅ Complete |
| **Overall** | **12 / 12 exercise files** | **✅ Current scope complete** |

```text
Progress: [████████████████████] 12 / 12
```

## Learning Path

### 1. Basics

Builds familiarity with arrays, loops, functions, and introductory string handling.

| File | Focus |
| :-- | :-- |
| `avg.c` | Calculates the average of an integer array. |
| `combine.c` | Reads ten values and reports their minimum, maximum, sum, and average. |
| `min_n_max.c` | Finds the minimum and maximum values in an array. |
| `string.c` | Implements basic string length, copy, and comparison routines. |
| `sum.c` | Calculates the sum of an integer array. |

### 2. Pointers

Applies pointer dereferencing, pointer arithmetic, and pointer-to-pointer parameters.

| File | Focus |
| :-- | :-- |
| `arraySum.c` | Traverses and modifies arrays through pointers; includes pointer-based sum and maximum examples. |
| `pointer-to-pointer.c` | Updates a pointer through a double-pointer parameter. |
| `reverseArray.c` | Reverses an array in place with left and right pointers. |
| `swap.c` | Swaps two integer values through their addresses. |

### 3. Memory Management

Introduces heap allocation and responsible cleanup with the C standard library.

| File | Focus |
| :-- | :-- |
| `dynamic_array.c` | Allocates an integer array with `malloc` and releases it with `free`. |
| `dynamic_memory.c` | Allocates a single integer through a pointer-to-pointer parameter. |
| `resize_dynamic_array.c` | Demonstrates `malloc`, `realloc`, `calloc`, and `free`. |

## Running an Exercise

### Prerequisites

- A C compiler, such as [Clang](https://clang.llvm.org/) or GCC
- PowerShell, Command Prompt, or another terminal

From the repository root, compile and run an individual exercise:

```powershell
clang .\exercises\Section-2-Pointers\reverseArray.c -o .\reverseArray.exe
.\reverseArray.exe
```

Most files contain an independent demonstration program. `combine.c` is the aggregate example in Section 1 and includes the array helper implementations from `sum.c`, `min_n_max.c`, and `avg.c`.

> **Tip:** Compile one demonstration file at a time. Building all `.c` files together will create duplicate `main` definitions, and the helper files used by `combine.c` are not intended to be built separately.

## Repository Layout

```text
exercises/
├── Section-1-Basics/
│   ├── avg.c
│   ├── combine.c
│   ├── min_n_max.c
│   ├── string.c
│   └── sum.c
├── Section-2-Pointers/
│   ├── arraySum.c
│   ├── pointer-to-pointer.c
│   ├── reverseArray.c
│   └── swap.c
└── Section-3-Memory-Management/
    ├── dynamic_array.c
    ├── dynamic_memory.c
    └── resize_dynamic_array.c
```

## Skills Practiced

- [x] Array traversal and aggregation
- [x] Functions and parameter passing
- [x] Custom string operations
- [x] Pointer arithmetic and dereferencing
- [x] Pointer-to-pointer usage
- [x] In-place array mutation
- [x] Heap allocation with `malloc` and `calloc`
- [x] Resizing allocations with `realloc`
- [x] Releasing heap memory with `free`

## Suggested Next Steps

- Add input validation and error handling for interactive programs.
- Check allocation results before dereferencing dynamically allocated memory.
- Separate reusable declarations into header files instead of including `.c` files directly.
- Add automated tests and compiler warning flags such as `-Wall -Wextra -Wpedantic`.
- Continue with structures, file I/O, and multi-file C programs.

## Notes

Generated executables, object files, and local IDE settings are excluded through `.gitignore`, keeping the repository focused on the source exercises.
