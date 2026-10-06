#include <stdio.h>
#include <stdlib.h>

typedef struct FreeBlock {
    struct FreeBlock *next;
} FreeBlock;

typedef struct {
    unsigned char *memory;
    size_t block_size;
    size_t block_count;
    FreeBlock *free_list;
} Pool;

int pool_init(Pool *pool) {
    pool->free_list = (FreeBlock *)pool->memory;
    for (size_t i = 0; i < pool->block_count; i++) {
        FreeBlock *block = pool->memory + (i * pool->block_size);
        if (i == pool->block_count - 1) {
            block->next = NULL;
        } else {
            block->next = (FreeBlock *)(pool->memory + ((i + 1) * pool->block_size));
        }
    }
    return 0;
}

FreeBlock *pool_alloc(Pool *pool) {
    //null check
    if (pool == NULL || pool->free_list == NULL) {
        return NULL;
    }
    //allocation
    FreeBlock *block = pool->free_list;
    pool->free_list = block->next;
    return block;
}

int main() {
    Pool pool;
    pool.block_count = 5;
    pool.block_size = 32;
    pool.memory = malloc(pool.block_size * pool.block_count);
    // get the address of block 3
    // unsigned char *block3 = pool.memory + (3 * pool.block_size);
    // printf("block 3 is %p",block3);
    pool_init(&pool);
    pool_alloc(&pool);
}