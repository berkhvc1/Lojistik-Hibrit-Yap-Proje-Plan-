#include "hash.h"
#include <stdio.h>
#include <string.h>

void hashInit(HashEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) table[i].dolu = false;
}

// TIP B: Katlama Metodu (Örn: 1101 -> 11 + 01 = 12)
int hashTipB(int key) {
    int part1 = key / 100;
    int part2 = key % 100;
    return (part1 + part2) % TABLE_SIZE;
}

// AÇIK ADRESLEME (Linear Probing)
void hashEkle(HashEntry table[], int id, char* icerik) {
    int index = hashTipB(id);
    int i = 0;
    
    while (table[(index + i) % TABLE_SIZE].dolu && i < TABLE_SIZE) {
        i++; // Çakışma varsa bir sonrakine bak
    }

    if (i < TABLE_SIZE) {
        int finalPos = (index + i) % TABLE_SIZE;
        table[finalPos].paketID = id;
        strcpy(table[finalPos].icerik, icerik);
        table[finalPos].dolu = true;
        printf("[Hash] Paket %d eklendi. Index: %d, Bellek Adresi: %p\n", id, finalPos, (void*)&table[finalPos]);
    } else {
        printf("[Hata] Hash tablosu dolu!\n");
    }
}