#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node {
    int sehirID;
    struct Node* next;
} Node;

typedef struct {
    int sehirSayisi;
    Node** adjLists;
    int* visited;
} Graph;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int s, int d);
void DFS(Graph* graph, int vertex);
void freeGraph(Graph* graph);

#endif