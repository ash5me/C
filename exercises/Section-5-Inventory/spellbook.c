/*
 * spellbook_practice.c
 * -------------------------------------------------------------------
 * Practice exercises built on the same pattern as your inventory.c:
 * a fixed-capacity array wrapped in a struct with a count field, plus
 * add / find / remove / iterate functions that operate on it through
 * a pointer.
 *
 * Fill in the five TODO functions below. Compile and run to see which
 * tests pass:
 *     gcc -std=c11 -Wall -Wextra spellbook_practice.c -o spellbook_practice
 *     ./spellbook_practice
 *
 * Every test starts failing. Implement one function at a time, working
 * top to bottom, and re-run after each one.
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/string.h"

#define MAX_SPELLS 10

typedef struct {
    char name[32];
    int mana_cost;
    int cooldown;
} Spell;

typedef struct {
    Spell spells[MAX_SPELLS];
    size_t count;
} SpellBook;

void spellbook_init(SpellBook *book) {
    book->count = 0;
}

/* ---------------------------------------------------------------------
 * Exercise 1 - bounded add
 * Same shape as inventory_add, but check capacity first this time.
 * Return true if the spell was added, false if the book was already full.
 * (Your original inventory_add had no such check - see the bottom test.)
 * ------------------------------------------------------------------- */
bool spellbook_add(SpellBook *book, const char *name, int mana_cost, int cooldown) {
    bool result = false;
    // check for capacity
    if (book ->count >= MAX_SPELLS) {
        return result;
    }
    Spell *spell = &book->spells[book->count];
    my_strcpy(spell->name,name);
    spell->cooldown = cooldown;
    spell->mana_cost = mana_cost;
    result = true;

    book->count++;

    return result;
}

/* ---------------------------------------------------------------------
 * Exercise 2 - find by name
 * Same pattern as inventory_find: linear scan, return a pointer to the
 * matching Spell, or NULL if nothing matches.
 * ------------------------------------------------------------------- */
Spell *spellbook_find(SpellBook *book, const char *name) {
    // TODO: implement
    //(void)book; (void)name;
    for (size_t i = 0; i < book->count; i++) {
        if(my_strcmp(book->spells[i].name, name) == 0) {
            return &book->spells[i];
        }
    }
    return NULL;
}

/* ---------------------------------------------------------------------
 * Exercise 3 - swap-remove
 * inventory_remove shifted every following element down by one to keep
 * order. Here, order does NOT matter: instead of shifting, move the
 * LAST spell into the slot being removed, then shrink count by one.
 * (O(1) instead of O(n) - the trick engines use for unordered lists
 * like bullets or particles.)
 * ------------------------------------------------------------------- */
bool spellbook_remove(SpellBook *book, size_t index) {
    bool result = false;
    if (index >= book->count) {
        return result;
    }
    //find the element and replace it with last element
    book->spells[index] = book->spells[book->count - 1];
    book->count--;
    return result = true;
}

/* ---------------------------------------------------------------------
 * Exercise 4 - learn-or-upgrade
 * If a spell with this name is already known, don't add a duplicate -
 * just add `bonus` to its existing mana_cost.
 * If it's a new name, add it as a new spell (respect capacity).
 * ------------------------------------------------------------------- */
void spellbook_learn(SpellBook *book, const char *name, int mana_cost, int cooldown, int bonus) {
    for (size_t i = 0; i < book->count; i++) {
        if (my_strcmp(book->spells[i].name, name) == 0) {
            printf("Nothing found");
            book->spells[i].mana_cost += bonus;
            return;
        }
    }

    spellbook_add(book, name, mana_cost, cooldown);
}

/* ---------------------------------------------------------------------
 * Exercise 5 - aggregate
 * Sum mana_cost across every known spell.
 * ------------------------------------------------------------------- */
int spellbook_total_mana(const SpellBook *book) {
    // TODO: implement
    //(void)book;
    int sum = 0;
    for (size_t i =0; i < book->count; i++) {
        sum += book->spells[i].mana_cost;
    }
    return sum;
}

void spellbook_print(const SpellBook *book) {
    for (size_t i = 0; i < book->count; i++) {
        const Spell *s = &book->spells[i];
        printf("  %-12s mana:%-3d cooldown:%d\n", s->name, s->mana_cost, s->cooldown);
    }
}

/* --------------------------- test harness --------------------------- */
static int tests_run = 0, tests_passed = 0;
#define CHECK(cond, desc) do { \
    tests_run++; \
    if (cond) { tests_passed++; printf("[PASS] %s\n", desc); } \
    else { printf("[FAIL] %s\n", desc); } \
} while (0)

int main(void) {
    SpellBook book;
    spellbook_init(&book);

    CHECK(spellbook_add(&book, "Fireball", 20, 3) == true, "add Fireball");
    CHECK(spellbook_add(&book, "Heal", 15, 1) == true, "add Heal");
    CHECK(spellbook_add(&book, "Ice Lance", 12, 2) == true, "add Ice Lance");
    CHECK(book.count == 3, "count is 3 after three adds");

    Spell *s = spellbook_find(&book, "Heal");
    CHECK(s != NULL && s->mana_cost == 15, "find existing spell (Heal)");
    CHECK(spellbook_find(&book, "Lightning") == NULL, "find missing spell returns NULL");

    CHECK(spellbook_remove(&book, 0) == true, "remove index 0 (Fireball) succeeds");
    CHECK(book.count == 2, "count is 2 after remove");
    CHECK(strcmp(book.spells[0].name, "Ice Lance") == 0, "swap-remove moved last spell into slot 0");

    spellbook_learn(&book, "Heal", 15, 1, 5);
    CHECK(book.count == 2, "learning an existing spell doesn't add a duplicate");
    s = spellbook_find(&book, "Heal");
    CHECK(s != NULL && s->mana_cost == 20, "existing spell's mana_cost increased by bonus");

    spellbook_learn(&book, "Blizzard", 30, 5, 0);
    CHECK(book.count == 3, "learning a new spell adds it");

    CHECK(spellbook_total_mana(&book) == 62, "total mana across all spells is correct");

    SpellBook full;
    spellbook_init(&full);
    for (int i = 0; i < MAX_SPELLS; i++) {
        char name[32];
        snprintf(name, sizeof(name), "Spell%d", i);
        char desc[64];
        snprintf(desc, sizeof(desc), "fill book to capacity (%d/%d)", i + 1, MAX_SPELLS);
        CHECK(spellbook_add(&full, name, 1, 1) == true, desc);
    }
    CHECK(spellbook_add(&full, "One Too Many", 1, 1) == false,
          "add refuses past capacity (your original inventory_add had no such guard)");

    printf("\n%d/%d tests passed\n", tests_passed, tests_run);
    printf("\nCurrent spellbook:\n");
    spellbook_print(&book);
    return 0;
}