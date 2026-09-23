#include <stdio.h>

typedef struct {
    char name[32];
    int health;
    int max_health;
    int attack;
    int defense;
} Character;

void character_attack(Character *attacker, Character *target) {
    // damage = attack - defense (only be positive number)
    int damage = attacker->attack - target->defense;

    if (damage > 0) {
        if (target->health > damage) {
            target->health -= damage; // reducing health by the damage taken for the target
        } else {
            target->health = 0;
        }
    }
    
    return;
}

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
    Character hero = {"Ash",70,100,6,10};
    Character enemy = {"Goblin", 50, 50, 3, 7};

    character_heal(&hero,95);
    printf("Current health : %d\n", hero.health);

    character_attack(&hero,&enemy);
    printf("Current defender's health : %d\n", enemy.health);

    if(character_is_alive(&hero)) {
        printf("Character is alive %s\n", hero.name);
    } else {
        printf("Character is dead! %s\n", hero.name);
    }
    return 0;
}