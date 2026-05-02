#include <stdio.h>
#include "hash.h"
#include "graph.h"

int main() {
    HashEntry paketTablosu[TABLE_SIZE];
    hashInit(paketTablosu);
    Graph* lojistikAgi = createGraph(10); // Maks 10 sehir

    int secim, id, s, d;
    char icerik[50];

    printf("BEKIR BERK KAHVECI - LOJISTIK OTOMASYONU (11)\n");

    while(1) {
        printf("\n1-Paket Ekle  2-Sehir Baglantisi  3-DFS Rota  0-Cikis: ");
        if (scanf("%d", &secim) != 1) break;

        if(secim == 1) {
            printf("ID ve Icerik girin: ");
            scanf("%d %s", &id, icerik);
            hashEkle(paketTablosu, id, icerik);
        } else if(secim == 2) {
            printf("Kaynak ve Hedef Sehir (0-9): ");
            scanf("%d %d", &s, &d);
            addEdge(lojistikAgi, s, d);
        } else if(secim == 3) {
            printf("Baslangic Sehri: ");
            scanf("%d", &s);
            for(int i=0; i<10; i++) lojistikAgi->visited[i] = 0; // Reset
            DFS(lojistikAgi, s);
        } else if(secim == 0) break;
    }

    freeGraph(lojistikAgi);
    return 0;
}