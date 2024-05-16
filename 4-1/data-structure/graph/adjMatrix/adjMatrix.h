#pragma once
#define MAX_VERTEX 30

typedef struct graphType {
    int n; // 그래프의 정점 개수
    int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // 그래프에 대한 30x30 인접행렬
}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);