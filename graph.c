#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

// 1. Graf Yapısını Başlatma (MALLOC Kullanımı)
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph)); 
    graph->sehirSayisi = vertices;

    // Komşuluk listesi ve ziyaret edilenler dizisi için yer ayır
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// 2. Şehirler Arası Bağlantı Kurma (ÇIKTI VEREN VERSİYON)
void addEdge(Graph* graph, int s, int d) {
    // Her yeni kenar/bağlantı bir Node (Düğüm) demektir
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sehirID = d;

    // Yeni düğümü listenin başına ekle (Bağlı Liste mantığı)
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    // İŞTE VİDEODA GÖSTERECEĞİN ÇIKTI:
    printf("[Graf] Sehir %d -> Sehir %d baglantisi kuruldu. Dugum Adresi: %p\n", s, d, (void*)newNode);
}

// 3. Graf Gezinme: DFS (Numaranın sondan 2. rakamı 1 (tek) olduğu için)
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    // Bellek raporu için adresleri burada da basıyoruz
    printf(">> Sehir %d ziyaret ediliyor. (Liste Basi Adresi: %p)\n", vertex, (void*)&graph->adjLists[vertex]);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int bagliSehir = temp->sehirID;
        if (!graph->visited[bagliSehir]) {
            DFS(graph, bagliSehir);
        }
        temp = temp->next;
    }
}

// 4. Bellek Temizleme (Ödevdeki Bellek Raporu İçin Kritik)
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->sehirSayisi; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete); // Her bir düğümü serbest bırak
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
    printf("\n[Bellek] Graf yapisina ait tüm dinamik alanlar (malloclar) free edildi.\n");
}