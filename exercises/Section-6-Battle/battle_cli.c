#include <stdio.h>
#include "../include/battle.h"
#include <limits.h>
#include <errno.h>
#include <ctype.h>

int main() {
    Character hero = {"Ash", 100, 100, 15, 5};
    Character enemy = {"Goblin", 60, 60, 10, 3};
    while (character_is_alive(&hero) && character_is_alive(&enemy)) {

    int choice;
    char buffer[128];

    // print menu
    printf("1. Attack\n");
    printf("2. Heal\n");

    // read player's choice & handle input validation, allow only int
    printf("Choose: ");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char *end;
        errno = 0;
        long val = strtol(buffer, &end, 10);

        // Check for conversion errors, overflow, or non-integer input
        if (errno == ERANGE || val < INT_MIN || val > INT_MAX || 
            end == buffer || 
            (*end != '\n' && *end != '\0' && !isspace((unsigned char)*end))) {
            printf("Invalid integer. Please try again: ");
            continue;
        }

        choice = (int)val;
        break; // Valid integer received
    }

    //turns
    if (choice == 1) {
        printf("\n");
        printf("===== BATTLE STARTS ===\n");
        printf("\n");
        character_attack(&hero,&enemy);
        printf("%s attacks %s!\n", hero.name, enemy.name);
        printf("%s: %d/%d HP\n", enemy.name, enemy.health, enemy.max_health);
    } else if (choice == 2) {
        character_heal(&hero,20);
        printf("%s heals! and current health : %d\n", hero.name, hero.health);
        // printf("%s attacks %s!\n", enemy.name, hero.name);
        // printf("%s: %d/%d HP\n", hero.name, hero.health, hero.max_health);
    } else {
        printf("Invalid input");
        continue;
    }

    //check life
    if (character_is_alive(&enemy)) {
            character_attack(&enemy,&hero);
            printf("%s attacks %s!\n", enemy.name, hero.name);
            printf("%s: %d/%d HP\n", hero.name, hero.health, hero.max_health);
        }

    }

    //death state check
    if (!character_is_alive(&hero)) {
        printf("Ash has been defeated!\nGoblin wins!");
    } else if (!character_is_alive(&enemy)) {
        printf("Goblin has been defeated!\nAsh wins!");
    }
}