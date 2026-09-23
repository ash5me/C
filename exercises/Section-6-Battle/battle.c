#include <stdio.h>

typedef struct {
    char name[32];
    int health;
    int max_health;
    int attack;
    int defense;
} Character;

void character_attack(Character *attacker, Character *target);

void character_heal(Character *character, int amount) {
    //add amount and health //if total exceeds, health = max_health
    if (amount < 0) {
        return;
    }
    character->health += amount;
    if (character->health > character->max_health) {
        character->health = character->max_health;
    }
}

int character_is_alive(const Character *character) {
    return character->health > 0;
}

int main() {
    Character hero = {"Ash",10,100,5,10};

    character_heal(&hero,-95);

    printf("Current health : %d\n", hero.health);

    if(character_is_alive(&hero)) {
        printf("Character is alive %s\n", hero.name);
    } else {
        printf("Character is dead! %s\n", hero.name);
    }
    return 0;
}