#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
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

//remove
void inventory_remove(Inventory *inventory, size_t index) {
    if (index >= inventory->count) return; // guard against bad index

    for (size_t i = index; i + 1 < inventory->count; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }
    inventory->count--;
}

//find
Item *inventory_find(Inventory *inventory, const char *name) {
    // take the item name and check with the name stored in item array
    //char *ptr = &inventory->items[*inventory->items->name];
    for (size_t i = 0; i < inventory->count; i++) {
        //compare
        if (my_strcmp(inventory->items[i].name, name)) {
            return &inventory->items[i];
        }
    }
    return NULL;
}

int main() {
    Inventory inventory;
    
    inventory_init(&inventory);

    inventory_add(&inventory, "Health Potion", 3, 0.5f);
    inventory_add(&inventory, "Iron Sword", 1, 4.0f);
    inventory_add(&inventory, "Shield", 1, 6.0f);
    
    inventory_remove(&inventory, 1);

    Item *item = inventory_find(&inventory, "Shield");
    if (item != NULL) {
    printf("%s: %d\n", item->name, item->quantity);
    }

    printf("Count: %zu\n", inventory.count);
    
}