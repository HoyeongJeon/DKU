#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType* g, int v) {
    graphNode* w;
    top = NULL;
    push(v);                // 스택의 top 설정
    g->visited[v] = TRUE;   // 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
    printf(" %c", v + 65);  // 정점 v를 방문했으므로 해당 배열값을 TRUE로 설정

    // 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
    while(!isStackEmpty()) {
        
    }
}