# C Programming Exercises

> A focused set of C exercises that builds from core language fundamentals to pointers and dynamic memory management.

## Progress at a Glance

| Current scope | Progress | Status |
| :-- | :-- | :-- |
| **Section 1 — Basics** | 5 / 5 exercises | ✅ Complete |
| **Section 2 — Pointers** | 4 / 4 exercises | ✅ Complete |
| **Section 3 — Memory Management** | 7 / 7 exercises | ✅ Complete |
| **Overall** | **16 / 16 exercise files** | **✅ Current scope complete** |

```text
Progress: [████████████████████] 16 / 16
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
| `dangling_pointer.c` | Demonstrates why a pointer must not be dereferenced after its allocation has been released. |
| `double_free.c` | Explores use-after-free behavior and includes a commented double-free example for discussion. |
| `dynamic_2D_array.c` | Allocates, uses, and releases a two-dimensional integer matrix through an array of row pointers. |
| `dynamic_array.c` | Allocates an integer array with `malloc` and releases it with `free`. |
| `dynamic_memory.c` | Allocates a single integer through a pointer-to-pointer parameter. |
| `memory_leak.c` | Illustrates a memory leak caused by an omitted `free` call. |
| `resize_dynamic_array.c` | Demonstrates `malloc`, `realloc`, `calloc`, and `free`. |

> **Safety note:** `dangling_pointer.c`, `double_free.c`, and `memory_leak.c` are learning examples that intentionally show unsafe memory-management patterns. Read and modify them carefully; their current behavior is not suitable for production code.

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
    ├── dangling_pointer.c
    ├── double_free.c
    ├── dynamic_2D_array.c
    ├── dynamic_array.c
    ├── dynamic_memory.c
    ├── memory_leak.c
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
- [x] Dynamically allocated two-dimensional arrays
- [x] Recognizing dangling pointers, use-after-free, double-free, and memory leaks

## Suggested Next Steps

- Add input validation and error handling for interactive programs.
- Check every allocation result before dereferencing dynamically allocated memory.
- Separate reusable declarations into header files instead of including `.c` files directly.
- Add automated tests and compiler warning flags such as `-Wall -Wextra -Wpedantic`.
- Use runtime memory diagnostics, such as Clang's AddressSanitizer, when experimenting with allocation and cleanup.
- Continue with structures, file I/O, and multi-file C programs.

## Notes

Generated executables, object files, and local IDE settings are excluded through `.gitignore`, keeping the repository focused on the source exercises.
