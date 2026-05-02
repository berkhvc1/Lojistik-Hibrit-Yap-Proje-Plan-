#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct {
    int paketID;
    char icerik[50];
    bool dolu;
} HashEntry;

void hashInit(HashEntry table[]);
int hashTipB(int key); // Katlama (Folding) Metodu
void hashEkle(HashEntry table[], int id, char* icerik);

#endif