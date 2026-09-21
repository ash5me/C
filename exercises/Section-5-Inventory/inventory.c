#include <stdio.h>
#include <stddef.h>
#include "../include/string.h"

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

//add
void inventory_add(Inventory *inventory, const char *name, int quantity, float weight) {
    Item *item = &inventory->items[inventory->count];

    my_strcpy(item->name, name);
    item->quantity = quantity;
    item->weight = weight;

    inventory->count++;
}

int main() {
    Inventory inventory;
    
    inventory_init(&inventory);

    inventory_add(&inventory, "Health Potion", 3, 0.5f);
    inventory_add(&inventory, "Iron Sword", 1, 4.0f);

    printf("Count: %zu\n", inventory.count);
    
}

// Expected Outcome : "Items: 0"