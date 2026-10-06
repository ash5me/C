# C Programming Exercises

> A progressive C programming learning repository focused on understanding the language, memory, pointers, data structures, and low-level programming concepts through hands-on exercises.

The repository is organized as a learning path rather than a collection of unrelated examples. Each stage builds on concepts introduced earlier and gradually moves toward systems programming and game-development-oriented programming.

---

## Learning Progress

| Stage                   | Area                                                                  | Status         |
| :---------------------- | :-------------------------------------------------------------------- | :------------- |
| **Stage 1**             | C Fundamentals, Pointers, Memory, Structs & Practical Data Structures | ✅ Complete     |
| **Stage 2 — Section 1** | Custom Allocators                                                     | 🚧 In Progress |
| **Stage 2 — Remaining** | Computer & Memory Fundamentals, Systems Programming                   | ⏳ Upcoming     |

### Stage 1 Progress

| Section                       | Exercises | Status     |
| :---------------------------- | :-------: | :--------- |
| Section 1 — Basics            |     5     | ✅ Complete |
| Section 2 — Pointers          |     4     | ✅ Complete |
| Section 3 — Memory Management |     7     | ✅ Complete |
| Section 4 — Structs           |     2     | ✅ Complete |
| Section 5 — Inventory         |     2     | ✅ Complete |
| Section 6 — Battle            |     2     | ✅ Complete |

```text
Stage 1
[████████████████████] Complete

Stage 2
[███░░░░░░░░░░░░░░░░░] In Progress
```

---

# Stage 1 — C Fundamentals

Stage 1 establishes the core C knowledge required for working with memory, data structures, and eventually systems/game programming.

---

## 1. Basics

Introduces arrays, loops, functions, aggregation, and basic string manipulation.

| File          | Focus                                                              |
| :------------ | :----------------------------------------------------------------- |
| `avg.c`       | Calculates the average of an integer array.                        |
| `combine.c`   | Reads values and reports their minimum, maximum, sum, and average. |
| `min_n_max.c` | Finds minimum and maximum values in an array.                      |
| `string.c`    | Implements basic string length, copy, and comparison routines.     |
| `sum.c`       | Calculates the sum of an integer array.                            |

### Concepts Practiced

* Variables
* Basic types
* Arrays
* Array indexing
* Loops
* Functions
* Function parameters
* Integer and floating-point arithmetic
* `sizeof`
* Strings
* Null-terminated character arrays
* Basic string manipulation

---

# 2. Pointers

Introduces direct memory access through pointers and gradually builds toward pointer-based programming.

| File                   | Focus                                                |
| :--------------------- | :--------------------------------------------------- |
| `arraySum.c`           | Traverses and modifies arrays using pointers.        |
| `pointer-to-pointer.c` | Changes a caller's pointer through a double pointer. |
| `reverseArray.c`       | Reverses an array in place using pointer arithmetic. |
| `swap.c`               | Swaps values through their addresses.                |

### Concepts Practiced

* Pointer declaration
* Address-of operator `&`
* Dereference operator `*`
* Pointer arithmetic
* Arrays and pointers
* Passing addresses to functions
* Modifying caller-owned data
* `const` pointers and pointed-to data
* Pointer-to-pointer parameters
* In-place algorithms

Example:

```c
void set_pointer(int **ptr, int *target) {
    *ptr = target;
}
```

This demonstrates an important C pattern: a function can modify the caller's pointer when given its address.

---

# 3. Memory Management

Introduces dynamically allocated memory and the responsibilities that come with owning heap allocations.

| File                     | Focus                                                                          |
| :----------------------- | :----------------------------------------------------------------------------- |
| `dangling_pointer.c`     | Demonstrates accessing memory after it has been released.                      |
| `double_free.c`          | Demonstrates invalid memory use and the dangers of freeing memory incorrectly. |
| `dynamic_2D_array.c`     | Allocates and releases a matrix using row pointers.                            |
| `dynamic_array.c`        | Allocates and releases a dynamic integer array.                                |
| `dynamic_memory.c`       | Allocates an integer through a pointer-to-pointer parameter.                   |
| `memory_leak.c`          | Demonstrates a memory leak caused by missing `free`.                           |
| `resize_dynamic_array.c` | Practices `malloc`, `calloc`, `realloc`, and `free`.                           |

### Concepts Practiced

* Stack vs heap
* `malloc`
* `calloc`
* `realloc`
* `free`
* Dynamic arrays
* Dynamic two-dimensional arrays
* Allocation failure
* Memory leaks
* Dangling pointers
* Use-after-free
* Double-free errors
* Ownership
* Lifetime of dynamically allocated objects
* Pointer-to-pointer allocation

> **Safety note:** Some files intentionally contain unsafe memory-management examples. They exist to demonstrate bugs and should not be copied into production code.

---

# 4. Structs

Introduces user-defined data types and dynamically allocated structures.

| File             | Focus                                                      |
| :--------------- | :--------------------------------------------------------- |
| `structs.c`      | Creates and manages a dynamically allocated `Player`.      |
| `multiStructs.c` | Allocates and initializes an array of `Player` structures. |

Example structure:

```c
typedef struct {
    int id;
    int health;
    int mana;
} Player;
```

### Concepts Practiced

* `struct`
* `typedef`
* Structure members
* Structure pointers
* `->` operator
* Arrays of structures
* Dynamically allocated structures
* Pointer-to-pointer cleanup

Example:

```c
void destroy_player(Player **player) {
    free(*player);
    *player = NULL;
}
```

Setting the caller's pointer to `NULL` after releasing the allocation makes accidental reuse easier to detect and avoid.

---

# 5. Inventory

Builds a practical fixed-capacity collection using structures, arrays, pointers, and custom string operations.

| File          | Focus                                                                                      |
| :------------ | :----------------------------------------------------------------------------------------- |
| `inventory.c` | Implements initialization, insertion, removal, lookup, and iteration.                      |
| `spellbook.c` | Extends the pattern with capacity checking, swap-remove, upgrades, aggregation, and tests. |

The inventory contains:

```c
typedef struct {
    char name[32];
    int quantity;
    float weight;
} Item;
```

The collection contains up to 20 items:

```c
typedef struct {
    Item items[20];
    size_t count;
} Inventory;
```

The spellbook uses a similar fixed-capacity design with a maximum of 10 spells.

### Concepts Practiced

* Fixed-capacity collections
* Collection initialization
* Adding elements
* Finding elements
* Removing elements
* Ordered removal
* Swap-remove
* Updating existing elements
* Aggregation
* Iteration
* Basic automated testing

---

# 6. Battle

Applies the previous C concepts to a small game-oriented simulation.

| File           | Focus                                                        |
| :------------- | :----------------------------------------------------------- |
| `battle.c`     | Implements character attacks, healing, and alive/dead state. |
| `battle_cli.c` | Provides a command-line battle loop with input validation.   |

The battle system uses:

```c
typedef struct {
    char name[32];
    int health;
    int max_health;
    int attack;
    int defense;
} Character;
```

### Concepts Practiced

* Structures
* Pointers
* Functions operating on game state
* State changes
* Input validation
* Command-line interaction
* Simple game logic
* Separation between game logic and CLI code

---

# Stage 2 — Memory & Computer Fundamentals

Stage 2 moves beyond simply *using* memory and focuses on understanding how memory and low-level systems actually work.

The goal is to develop the mental model required for systems programming, custom allocators, game engines, and performance-sensitive software.

---

## Stage 2 Learning Goals

The major topics include:

* Object lifetime
* Storage duration
* Memory ownership
* Stack and heap behavior
* Memory layout
* Alignment
* Padding
* Pointer arithmetic
* Allocation strategies
* Custom allocators
* Cache behavior
* Virtual memory
* Data locality
* Allocation performance
* Fragmentation
* Systems-level debugging

A particularly important concept established during Stage 2 is:

> A pointer variable and the object it points to have independent lifetimes.

For example:

```c
int *p = malloc(sizeof(int));
```

There are two separate things here:

```text
Stack / automatic storage
┌─────────────┐
│ p           │
│ address ───────────────┐
└─────────────┘          │
                         ▼
                    Heap allocation
                    ┌─────────────┐
                    │ int object  │
                    │    42       │
                    └─────────────┘
```

The pointer variable can cease to exist while the allocated object remains alive, and the allocated object can be released while the pointer variable still exists.

Understanding this distinction is fundamental to reasoning about C memory.

---

# Stage 2 — Section 1: Custom Allocators

The first practical Stage 2 section focuses on implementing simplified memory allocators.

```text
stage-2/
├── include/
│   └── arena.h
│
└── Section-1-Allocators/
    ├── arena.c
    └── pool.c
```

---

## Arena Allocator

`arena.c` implements a simple linear/bump allocator.

The allocator maintains:

```c
typedef struct {
    unsigned char *memory;
    size_t capacity;
    size_t offset;
} Arena;
```

The basic idea is:

```text
Arena memory

0                                             capacity
│------------------------------------------------│
│ Used memory              │ Free memory         │
│                          │                     │
│ <------ offset --------> │                     │
│                          │                     │
└──────────────────────────┴─────────────────────┘
```

An allocation simply advances the offset:

```text
Before:

[ used ][---------------- free ----------------]

             ↑
           offset


Allocate 32 bytes:

[ used ][ 32 bytes ][------- free -----------]

                       ↑
                     offset
```

### Concepts Practiced

* Bump/linear allocation
* Allocation offsets
* Capacity checks
* Pointer arithmetic
* Raw byte storage
* Alignment
* Alignment padding
* `_Alignof`
* Power-of-two alignment
* Allocation failure

The allocator also includes an aligned allocation operation:

```c
arena_alloc_aligned(...)
```

This introduces an important low-level concept: an object's address may need to satisfy a particular alignment requirement.

---

## Pool Allocator

`pool.c` introduces a fixed-size memory pool.

Instead of allocating objects of arbitrary sizes, the pool divides a memory region into equally sized blocks.

```text
Pool

┌────────┬────────┬────────┬────────┬────────┐
│ Block0 │ Block1 │ Block2 │ Block3 │ Block4 │
└────────┴────────┴────────┴────────┴────────┘
    ▲
    │
 free_list
```

Unused blocks are connected together as a free list.

Each free block temporarily stores the pointer to the next available block:

```c
typedef struct FreeBlock {
    struct FreeBlock *next;
} FreeBlock;
```

### Concepts Practiced

* Fixed-size allocation
* Free lists
* Intrusive data structures
* Memory pools
* Pointer manipulation
* Allocation without repeatedly calling `malloc`
* Constant-time allocation from a free list

This pattern is particularly relevant to systems such as:

* Game objects
* Particles
* Bullets
* Entities
* Temporary simulation objects
* Networking objects
* Resource pools

---

# Allocator Concepts

The allocator exercises introduce two different allocation strategies.

### Arena

```text
Allocate → move forward
Allocate → move forward
Allocate → move forward
Reset   → reuse everything
```

Advantages:

* Very simple
* Very fast
* Excellent locality
* Minimal bookkeeping

Typical use cases:

* Temporary frame data
* Level loading
* Parsing
* Scratch memory
* Short-lived objects

---

### Pool

```text
Free → Block → Block → Block → NULL
          ↑
       free_list
```

Advantages:

* Fast allocation
* Fast deallocation
* Predictable memory usage
* No external fragmentation between blocks

Typical use cases:

* Particles
* Projectiles
* Entities
* Fixed-size game objects

---

# Repository Structure

```text
.
├── exercises/
│   │
│   ├── stage-1/
│   │   ├── include/
│   │   │   ├── battle.h
│   │   │   └── string.h
│   │   │
│   │   ├── Section-1-Basics/
│   │   │   ├── avg.c
│   │   │   ├── combine.c
│   │   │   ├── min_n_max.c
│   │   │   ├── string.c
│   │   │   └── sum.c
│   │   │
│   │   ├── Section-2-Pointers/
│   │   │   ├── arraySum.c
│   │   │   ├── pointer-to-pointer.c
│   │   │   ├── reverseArray.c
│   │   │   └── swap.c
│   │   │
│   │   ├── Section-3-Memory-Management/
│   │   │   ├── dangling_pointer.c
│   │   │   ├── double_free.c
│   │   │   ├── dynamic_2D_array.c
│   │   │   ├── dynamic_array.c
│   │   │   ├── dynamic_memory.c
│   │   │   ├── memory_leak.c
│   │   │   └── resize_dynamic_array.c
│   │   │
│   │   ├── Section-4-Structs/
│   │   │   ├── multiStructs.c
│   │   │   └── structs.c
│   │   │
│   │   ├── Section-5-Inventory/
│   │   │   ├── inventory.c
│   │   │   └── spellbook.c
│   │   │
│   │   └── Section-6-Battle/
│   │       ├── battle.c
│   │       └── battle_cli.c
│   │
│   └── stage-2/
│       ├── include/
│       │   └── arena.h
│       │
│       └── Section-1-Allocators/
│           ├── arena.c
│           └── pool.c
│
├── .gitignore
└── README.md
```

---

# Compiling and Running Exercises

## Prerequisites

A C compiler such as:

* GCC
* Clang

Recommended warning flags:

```text
-Wall -Wextra -Wpedantic
```

---

## GCC

For example:

```powershell
gcc -std=c11 -Wall -Wextra .\exercises\stage-1\Section-2-Pointers\reverseArray.c -o .\reverseArray.exe
.\reverseArray.exe
```

For Stage 2:

```powershell
gcc -std=c11 -Wall -Wextra .\exercises\stage-2\Section-1-Allocators\arena.c -o .\arena.exe
.\arena.exe
```

---

## Clang

```powershell
clang -std=c11 -Wall -Wextra -Wpedantic .\exercises\stage-1\Section-2-Pointers\reverseArray.c -o .\reverseArray.exe
.\reverseArray.exe
```

---

## Spellbook Tests

The spellbook contains its own test harness:

```powershell
gcc -std=c11 -Wall -Wextra .\exercises\stage-1\Section-5-Inventory\spellbook.c -o .\spellbook.exe
.\spellbook.exe
```

The test harness checks:

* Adding spells
* Capacity limits
* Searching
* Removing
* Swap-remove behavior
* Upgrading existing spells
* Learning new spells
* Aggregate mana calculation

---

> **Important:** Compile individual exercises separately. Many source files contain their own `main()` function, so compiling unrelated exercises together will result in duplicate `main` definitions.

---

# Skills Practiced

## C Fundamentals

* [x] Variables and basic types
* [x] Arrays
* [x] Loops
* [x] Functions
* [x] Function parameters
* [x] Array aggregation
* [x] Strings
* [x] Null-terminated strings
* [x] Custom string operations

## Pointers

* [x] Pointer declaration
* [x] Address-of operator
* [x] Dereferencing
* [x] Pointer arithmetic
* [x] Passing addresses to functions
* [x] Pointer-to-pointer parameters
* [x] Array traversal using pointers
* [x] In-place modification
* [x] `const` pointer parameters

## Memory Management

* [x] Stack vs heap
* [x] Object lifetime
* [x] Ownership
* [x] `malloc`
* [x] `calloc`
* [x] `realloc`
* [x] `free`
* [x] Dynamic arrays
* [x] Dynamic two-dimensional arrays
* [x] Dynamically allocated structures
* [x] Allocation failure
* [x] Memory leaks
* [x] Dangling pointers
* [x] Use-after-free
* [x] Double-free errors
* [x] Pointer lifetime vs pointed-object lifetime

## Structures

* [x] `struct`
* [x] `typedef`
* [x] Structure members
* [x] Structure pointers
* [x] `->`
* [x] Arrays of structures
* [x] Dynamically allocated structures
* [x] Pointer-to-pointer cleanup

## Data Structures & Practical Patterns

* [x] Fixed-capacity collections
* [x] Collection initialization
* [x] Adding elements
* [x] Finding elements
* [x] Removing elements
* [x] Ordered removal
* [x] Swap-remove
* [x] Updating elements
* [x] Aggregation
* [x] Iteration
* [x] Basic test harnesses
* [x] Linear search

## Custom Allocators — Stage 2

* [x] Arena allocator fundamentals
* [x] Bump allocation
* [x] Allocation offsets
* [x] Capacity checks
* [x] Raw byte storage
* [x] Alignment
* [x] Alignment padding
* [x] `_Alignof`
* [x] Power-of-two alignment
* [x] Fixed-size memory pools
* [x] Free lists
* [x] Intrusive free-list nodes

---

# Design Patterns Practiced

## Pointer-to-Pointer Resource Management

When a function needs to modify the caller's pointer, pass the address of that pointer:

```c
void allocate_int(int **ptr) {
    *ptr = malloc(sizeof(int));
}
```

This allows the function to change the caller's pointer itself.

The same pattern is useful for cleanup:

```c
void destroy_player(Player **player) {
    free(*player);
    *player = NULL;
}
```

---

## Fixed-Capacity Collections

The inventory and spellbook use an array plus a count:

```text
┌─────────────────────────────┐
│ Fixed-size array            │
│                             │
│ [ item ][ item ][ item ]... │
│             ↑               │
│           count             │
└─────────────────────────────┘
```

`count` represents the number of active elements rather than the total capacity.

---

## Linear Search

The collection exercises use a straightforward linear scan:

```c
for (size_t i = 0; i < book->count; i++) {
    if (my_strcmp(book->spells[i].name, name)) {
        return &book->spells[i];
    }
}
```

This provides a practical introduction to searching before moving toward more advanced data structures.

---

## Swap-Remove

When ordering does not matter, an element can be removed in constant time:

```c
book->spells[index] = book->spells[book->count - 1];
book->count--;
```

Instead of shifting every following element, the final element takes the removed element's place.

This is particularly useful for game-engine collections such as:

* Particles
* Bullets
* Enemies
* Entities
* Temporary effects

---

## Arena Allocation

Arena allocation replaces many individual allocations with a single larger allocation.

```text
malloc()
     │
     ▼
┌─────────────────────────────────┐
│             Arena               │
├────────────────┬────────────────┤
│ allocated data │ free space     │
└────────────────┴────────────────┘
                 ↑
               offset
```

Allocating memory simply advances the offset.

This provides a foundation for understanding how specialized allocators can outperform general-purpose allocation for specific workloads.

---

## Pool Allocation

A pool divides a large allocation into fixed-size blocks:

```text
┌────────┬────────┬────────┬────────┬────────┐
│ Block0 │ Block1 │ Block2 │ Block3 │ Block4 │
└────────┴────────┴────────┴────────┴────────┘
```

Available blocks are connected through a free list.

This introduces the concept of using the allocated memory itself to store allocator metadata.

---

# Development Philosophy

The exercises intentionally progress from:

```text
C Syntax
   ↓
Pointers
   ↓
Memory
   ↓
Object Lifetime
   ↓
Structures
   ↓
Data Structures
   ↓
Custom Allocators
   ↓
Systems Programming
   ↓
Game Programming
```

The purpose is not merely to memorize C syntax.

The goal is to develop an accurate mental model of:

* How data is represented
* Where data lives
* How long data lives
* Who owns memory
* How pointers refer to objects
* How memory can be organized
* How allocation strategies affect performance
* How low-level systems can be built from simple primitives

---

# Suggested Next Steps

## Stage 2

Continue developing the memory/computer fundamentals knowledge through progressively more difficult exercises.

Upcoming areas include:

* Memory layout
* Alignment and padding
* Pointer representation
* Object representation
* Data locality
* Cache behavior
* Virtual memory
* Fragmentation
* Ownership patterns
* Allocator design
* Allocation failure strategies
* More advanced allocator exercises

The existing arena and pool implementations will be extended rather than treated as isolated examples.

## Later Systems Programming

After the memory fundamentals are established:

* File I/O
* Multi-file C programs
* Header/source organization
* Function pointers
* Linked lists
* Stacks
* Queues
* Dynamic data structures
* Hash tables
* Networking
* Concurrency
* Threading
* Synchronization
* More advanced testing
* Debugging tools

## Eventually

The longer-term direction is toward game and engine programming:

```text
C Fundamentals
      ↓
Memory & Computer Fundamentals
      ↓
Systems Programming
      ↓
Zig Fundamentals
      ↓
Systems Projects
      ↓
Game Programming
      ↓
Custom Game Engine
      ↓
Gameplay / Game Systems
```

---

# Debugging and Memory Diagnostics

When experimenting with intentionally unsafe programs, use runtime diagnostics where available.

Recommended tools and techniques include:

### Compiler warnings

```text
-Wall -Wextra -Wpedantic
```

### AddressSanitizer

Useful for detecting problems such as:

* Use-after-free
* Buffer overflows
* Heap corruption
* Some memory leaks
* Invalid memory accesses

For example:

```powershell
gcc -std=c11 -Wall -Wextra -fsanitize=address -g program.c -o program.exe
```

---

# Notes

This repository is primarily a learning workspace.

Some programs intentionally demonstrate incorrect or unsafe behavior so that memory-management bugs can be observed and understood.

These examples should be treated as experiments rather than production-quality implementations.

Generated executables, object files, IDE configuration, logs, and temporary files are excluded through `.gitignore`.

The repository will continue to evolve as new stages and systems-programming exercises are added.
