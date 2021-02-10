#ifndef CHARACTER_DESERIALIZER_H
#define CHARACTER_DESERIALIZER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[51];
    unsigned int health;
    unsigned int strength;
    unsigned int defence;
} minion_t;

typedef struct {
    unsigned int fire;
    unsigned int cold;
    unsigned int lightning;
} elemental_resistance_t;

typedef struct {
    char name[51];
    unsigned int level;
    unsigned int health;
    unsigned int mana;
    unsigned int strength;
    unsigned int dexterity;
    unsigned int intelligence;
    unsigned int armour;
    unsigned int evasion;
    unsigned int leadership;
    size_t minion_count;
    elemental_resistance_t elemental_resistance;
    minion_t minions[3];
} character_v3_t;

int get_character(const char* filename, character_v3_t* out_character);

void deserialize_v1_to_v3(FILE* stream, character_v3_t* out_character);

void deserialize_v2_to_v3(FILE* stream, character_v3_t* out_character);

void deserialize_v3(FILE* stream, character_v3_t* out_character);

void remove_column(char* buffer);

void remove_comma(char* buffer);

size_t get_line_length(FILE* stream);

void match_key(char* token, character_v3_t* out_character);

#endif /* CHARACTER_DESERIALIZER_H */
