#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int health;
    int mana;
} Player;

Player *create_players(int count) {
    int id = 0;
    int health = 100;
    int mana = 50;
    Player *ptr = malloc(count * sizeof(Player));
        if (ptr == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
        }
    Player *current = ptr; // Assigning current outside of loop, to not initialize everytime
    // keeping everything inside loop
    for (int i=0; i < count; i++) {
        
        current -> id = id;
        current -> health = health;
        current -> mana = mana;
        current++;
    }
    return ptr;
}

int main() {
    int count = 3;

    Player *players = create_players(count);

    if (players == NULL) {
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf(
            "Player %d: Id:%d Health=%d Mana=%d\n",
            i+1,
            players[i].id,
            players[i].health,
            players[i].mana
        );
    }

    free(players);

    return 0;
}