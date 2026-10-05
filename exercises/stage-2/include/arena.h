#ifndef battle.h
#define battle.h

typedef struct {
    unsigned char *memory;
    size_t capacity;
    size_t offset;
} Arena;

void *arena_alloc(Arena *arena, size_t size);

#endif battle.h