#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

void DFS_adjList(graphType* g, int v) { // 그래프 g의 v번째 정점부터 깊이 우선 탐색
    graphNode* w;
    top = NULL; // 스택 top 설정
    push(v);    // 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
    g->visited[v] = TRUE; // 정점 v를 방문했으므로 해당 배열값을 TRUE로 설정
    printf(" %c", v + 65);

    // 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
    while(!isStackEmpty()) {
        w = g->adjList_H[v]; // 정점 v의 인접 정점을 탐색하기 위해 w에 저장
        while(w) {
            // 현재 정점 w를 방문하지 않았다면
            if(!g->visited[w->vertex]) {
                push(w->vertex); // 정점 w를 스택에 push
                g->visited[w->vertex] = TRUE; // 정점 w를 방문했으므로 해당 배열값을 TRUE로 설정
                printf(" %c", w->vertex + 65);
                v = w->vertex; 
                w = g->adjList_H[v];
            } else {
                w = w->link; // 정점 w를 방문했다면 다음 인접 정점으로 이동
            }
        }
        v = pop(); // 현재 정점에서 순회를 진행할 인접 정점이 더 없는 경우에 스택 pop!
    } // 스택이 공백이면 깊이 우선 탐색 종료
}