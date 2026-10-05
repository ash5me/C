#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *memory;
    size_t capacity;
    size_t offset;
} Arena;

void *arena_alloc(Arena *arena, size_t size) {
    if (size > arena->capacity - arena->offset) {
    return NULL;
    }

    size_t current_offset = arena->offset;
    void *ptr = arena->memory + current_offset;
    arena->offset += size;
    
    return ptr;

}

int is_power_of_two(size_t value) {
    return value != 0 && (value & (value - 1)) == 0;
}

size_t alignment_padding(size_t offset, size_t alignment) {
    // padding = alignment - current.offset % alignment
    // if alignment = padding then padding = 0
    size_t padding = alignment - (offset % alignment);
    if (alignment == padding) {
        return 0;
    }
    return padding;
}

void *arena_alloc_aligned(Arena *arena, size_t size, size_t alignment) {
    //1. Validate alignment
    if (!is_power_of_two(alignment)) {
        return NULL;
    }

    // 2. Calculate padding
    size_t padding = alignment_padding(arena->offset,alignment);
    
    // 3. Check available space
    size_t available = arena->capacity - arena->offset;
    
    if (padding > available) {
        return NULL;
    }

    available -= padding;

    if (size > available) {
        return NULL;
    }

    //4. Skip padding
    arena->offset += padding;

    //5. Get aligned address
    void *ptr = arena->memory + arena->offset;

    //6. Consume allocation
    arena->offset += size;

    return ptr;
}

int main() {
    Arena arena;
    arena.memory = malloc(1024);
    //handle allocation failure
    if (arena.memory == NULL) {
        printf("The allocation failed.");
        return 1;
    }
    arena.capacity = 1024;
    arena.offset = 0;
    int *numbers = arena_alloc(&arena, sizeof(int) * 10);
    // allocation check
    if (numbers == NULL) {
        printf("Arena allocation failed.\n");
        free(arena.memory);
        return 1;
    }
    for (int i=0; i<10; i++) {
        numbers[i] = i * 10;
    }
    free(arena.memory);
}
