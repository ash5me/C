#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int health;
    int mana;
} Player;

Player *create_player(int id, int health, int mana) {
    Player *ptr = malloc(sizeof(Player));
    if (ptr == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    ptr->id = id;
    ptr->health = health;
    ptr->mana = mana;
    return ptr;
}

int main() {
    Player *player = create_player(1, 100, 50);
    if (player == NULL) {
        return 1;
    }
    printf("ID: %d\n", player->id);
    printf("Health: %d\n", player->health);
    printf("Mana: %d\n", player->mana);

    free(player);

    return 0;
}