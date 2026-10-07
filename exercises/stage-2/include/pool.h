#ifndef POOL_H
#define POOL_H

#include <stddef.h>

typedef struct FreeBlock {
    struct FreeBlock *next;
} FreeBlock;

typedef struct {
    unsigned char *memory;
    size_t block_size;
    size_t block_count;
    FreeBlock *free_list;
} Pool;

int pool_init(Pool *pool);

FreeBlock *pool_alloc(Pool *pool);

int pool_free(Pool *pool, FreeBlock *block);

#endif /* POOL_H */