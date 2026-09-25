#ifndef BATTLE_H
#define BATTLE_H

typedef struct {
    char name[32];
    int health;
    int max_health;
    int attack;
    int defense;
} Character;

void character_attack(Character *attacker, Character *target);

void character_heal(Character *character, int amount);

int character_is_alive(const Character *character);


#endif