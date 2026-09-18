#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[32];
    int quantity;
    float weight;
} Item;

typedef struct {
    Item items[20];
    size_t count;
} Inventory;

void inventory_init(Inventory *inventory) {

    inventory->count=0;
}

int main() {
    Inventory inventory;
    
    inventory_init(&inventory);

    printf("Items: %zu\n", inventory.count);
}

// Expected Outcome : "Items: 0"