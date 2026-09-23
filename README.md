# C Programming Exercises

> A focused set of C exercises that builds progressively from core language fundamentals to pointers, dynamic memory management, structures, and practical data-structure patterns.

## Progress at a Glance

| Section                           |  Exercises  | Status                       |
| :-------------------------------- | :---------: | :--------------------------- |
| **Section 1 — Basics**            |    5 / 5    | ✅ Complete                   |
| **Section 2 — Pointers**          |    4 / 4    | ✅ Complete                   |
| **Section 3 — Memory Management** |    7 / 7    | ✅ Complete                   |
| **Section 4 — Structs**           |    2 / 2    | ✅ Complete                   |
| **Section 5 — Inventory**         |    2 / 2    | ✅ Complete                   |
| **Overall**                       | **20 / 20** | **✅ Current scope complete** |

```text
Progress: [████████████████████] 20 / 20
```

## Learning Path

### 1. Basics

Builds familiarity with arrays, loops, functions, aggregation, and introductory string handling.

| File          | Focus                                                                  |
| :------------ | :--------------------------------------------------------------------- |
| `avg.c`       | Calculates the average of an integer array.                            |
| `combine.c`   | Reads ten values and reports their minimum, maximum, sum, and average. |
| `min_n_max.c` | Finds the minimum and maximum values in an array.                      |
| `string.c`    | Implements basic string length, copy, and comparison routines.         |
| `sum.c`       | Calculates the sum of an integer array.                                |

### 2. Pointers

Applies pointer dereferencing, pointer arithmetic, pointer-to-pointer parameters, and in-place array manipulation.

| File                   | Focus                                                                                            |
| :--------------------- | :----------------------------------------------------------------------------------------------- |
| `arraySum.c`           | Traverses and modifies arrays through pointers; includes pointer-based sum and maximum examples. |
| `pointer-to-pointer.c` | Updates a pointer through a double-pointer parameter.                                            |
| `reverseArray.c`       | Reverses an array in place using left and right pointers.                                        |
| `swap.c`               | Swaps two integer values through their addresses.                                                |

### 3. Memory Management

Introduces heap allocation and responsible memory ownership using the C standard library.

| File                     | Focus                                                                                             |
| :----------------------- | :------------------------------------------------------------------------------------------------ |
| `dangling_pointer.c`     | Demonstrates why a pointer must not be dereferenced after its allocated memory has been released. |
| `double_free.c`          | Explores use-after-free behavior and contains a commented double-free example.                    |
| `dynamic_2D_array.c`     | Allocates, uses, and releases a two-dimensional integer matrix through an array of row pointers.  |
| `dynamic_array.c`        | Allocates an integer array with `malloc` and releases it with `free`.                             |
| `dynamic_memory.c`       | Allocates a single integer through a pointer-to-pointer parameter.                                |
| `memory_leak.c`          | Illustrates a memory leak caused by an omitted `free` call.                                       |
| `resize_dynamic_array.c` | Demonstrates `malloc`, `realloc`, `calloc`, and `free`.                                           |

> **Safety note:** `dangling_pointer.c`, `double_free.c`, and `memory_leak.c` intentionally demonstrate unsafe memory-management patterns for learning purposes. Do not copy these patterns into production code.

### 4. Structs

Introduces user-defined structures, dynamically allocated structs, structure pointers, and cleanup functions.

| File             | Focus                                                                                                                                                      |
| :--------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `structs.c`      | Creates and initializes a dynamically allocated `Player`, accesses its fields through `->`, and releases it through a pointer-to-pointer cleanup function. |
| `multiStructs.c` | Dynamically allocates multiple `Player` structs, initializes them, iterates through them, and releases the allocation.                                     |

The `Player` structure used in these exercises contains:

```c
typedef struct {
    int id;
    int health;
    int mana;
} Player;
```

### 5. Inventory

Builds a practical fixed-capacity data structure using structs, arrays, pointers, custom string functions, and collection operations.

| File          | Focus                                                                                                                                  |
| :------------ | :------------------------------------------------------------------------------------------------------------------------------------- |
| `inventory.c` | Implements a fixed-capacity inventory with initialization, add, remove, find, and print operations.                                    |
| `spellbook.c` | Extends the inventory pattern with bounded insertion, lookup, swap-remove, learn-or-upgrade behavior, aggregation, and a test harness. |

The inventory uses an `Item` structure containing:

```c
typedef struct {
    char name[32];
    int quantity;
    float weight;
} Item;
```

The inventory itself stores up to 20 items:

```c
typedef struct {
    Item items[20];
    size_t count;
} Inventory;
```

The spellbook exercise uses a similar pattern with a fixed capacity of 10 spells and includes automated checks for the implemented operations.

## Running an Exercise

### Prerequisites

* A C compiler such as [Clang](https://clang.llvm.org/) or GCC
* PowerShell, Command Prompt, or another terminal

From the repository root, compile and run an individual exercise:

```powershell
clang .\exercises\Section-2-Pointers\reverseArray.c -o .\reverseArray.exe
.\reverseArray.exe
```

For GCC:

```powershell
gcc .\exercises\Section-2-Pointers\reverseArray.c -o .\reverseArray.exe
.\reverseArray.exe
```

### Running the Spellbook Exercise

`spellbook.c` contains its own test harness:

```powershell
gcc -std=c11 -Wall -Wextra .\exercises\Section-5-Inventory\spellbook.c -o .\spellbook.exe
.\spellbook.exe
```

The exercise checks:

* Adding spells
* Counting stored spells
* Finding existing and missing spells
* Swap-removing an item
* Upgrading an existing spell
* Learning a new spell
* Calculating total mana
* Enforcing the maximum spell capacity

> **Tip:** Compile one demonstration file at a time. Several source files contain their own `main` function, so compiling every `.c` file together will result in duplicate `main` definitions.

`combine.c` is a special case in Section 1 because it directly includes the implementations from `sum.c`, `min_n_max.c`, and `avg.c`.

## Repository Layout

```text
.
├── exercises/
│   ├── include/
│   │   └── string.h
│   │
│   ├── Section-1-Basics/
│   │   ├── avg.c
│   │   ├── combine.c
│   │   ├── min_n_max.c
│   │   ├── string.c
│   │   └── sum.c
│   │
│   ├── Section-2-Pointers/
│   │   ├── arraySum.c
│   │   ├── pointer-to-pointer.c
│   │   ├── reverseArray.c
│   │   └── swap.c
│   │
│   ├── Section-3-Memory-Management/
│   │   ├── dangling_pointer.c
│   │   ├── double_free.c
│   │   ├── dynamic_2D_array.c
│   │   ├── dynamic_array.c
│   │   ├── dynamic_memory.c
│   │   ├── memory_leak.c
│   │   └── resize_dynamic_array.c
│   │
│   ├── section-4-Structs/
│   │   ├── multiStructs.c
│   │   └── structs.c
│   │
│   └── Section-5-Inventory/
│       ├── inventory.c
│       └── spellbook.c
│
├── .gitignore
└── README.md
```

## Skills Practiced

### C Fundamentals

* [x] Variables and basic types
* [x] Arrays
* [x] Loops
* [x] Functions
* [x] Function parameters
* [x] Array aggregation
* [x] Custom string operations

### Pointers

* [x] Pointer declaration and dereferencing
* [x] Pointer arithmetic
* [x] Passing addresses to functions
* [x] Pointer-to-pointer parameters
* [x] In-place array modification
* [x] Array traversal using pointers

### Memory Management

* [x] Heap allocation with `malloc`
* [x] Zero-initialized allocation with `calloc`
* [x] Resizing allocations with `realloc`
* [x] Releasing heap memory with `free`
* [x] Dynamically allocated arrays
* [x] Dynamically allocated two-dimensional arrays
* [x] Allocation through pointer-to-pointer parameters
* [x] Recognizing dangling pointers
* [x] Recognizing use-after-free
* [x] Recognizing double-free errors
* [x] Recognizing memory leaks

### Structures

* [x] Defining `struct` types
* [x] Using `typedef` with structures
* [x] Dynamically allocating structures
* [x] Accessing structure members with `->`
* [x] Managing arrays of structures
* [x] Cleaning up structure allocations
* [x] Using pointer-to-pointer cleanup functions

### Data Structures & Practical Patterns

* [x] Fixed-capacity collections
* [x] Collection initialization
* [x] Adding elements
* [x] Finding elements by name
* [x] Removing elements
* [x] Ordered removal through element shifting
* [x] Unordered removal through swap-remove
* [x] Updating existing elements
* [x] Aggregating values across a collection
* [x] Iterating over collections
* [x] Basic test-harness design

## Design Patterns Practiced

### Pointer-Based Resource Management

Several exercises use a pointer-to-pointer when a function needs to change the caller's pointer:

```c
void allocate_int(int **ptr) {
    *ptr = malloc(sizeof(int));
}
```

The same idea is used when destroying dynamically allocated structures:

```c
void destroy_player(Player **player) {
    free(*player);
    *player = NULL;
}
```

### Fixed-Capacity Collections

The inventory and spellbook exercises demonstrate a simple collection pattern:

```text
┌─────────────────────────────┐
│ Fixed-size array            │
│                             │
│ [ item ][ item ][ item ]... │
│             ↑               │
│           count             │
└─────────────────────────────┘
```

The `count` field tracks how many elements are currently in use.

### Linear Search

The inventory and spellbook implementations use a straightforward linear scan to find an element by name.

```c
for (size_t i = 0; i < book->count; i++) {
    if (my_strcmp(book->spells[i].name, name)) {
        return &book->spells[i];
    }
}
```

### Swap-Remove

`spellbook.c` introduces an alternative removal strategy when element order does not matter:

```c
book->spells[index] = book->spells[book->count - 1];
book->count--;
```

Instead of shifting every element after the removed item, the final element replaces it.

## Suggested Next Steps

* Add input validation and error handling to interactive programs.
* Check every allocation result before dereferencing dynamically allocated memory.
* Separate reusable declarations into header files instead of including `.c` files directly.
* Move reusable implementations into `.c` files and compile/link them separately.
* Add automated tests for the existing inventory functions.
* Add tests for allocation failure cases.
* Use compiler warning flags such as:

```text
-Wall -Wextra -Wpedantic
```

* Use runtime memory diagnostics such as AddressSanitizer while experimenting with allocation and cleanup.
* Continue with:

  * File I/O
  * Multi-file C programs
  * Function pointers
  * Linked lists
  * Stacks and queues
  * Dynamic data structures
  * More advanced testing

## Notes

Generated executables, object files, IDE settings, and local temporary files are excluded through `.gitignore`, keeping the repository focused on the C source exercises.

This repository is primarily a learning workspace. Some programs intentionally contain unsafe examples so that memory-management mistakes can be observed and understood.
