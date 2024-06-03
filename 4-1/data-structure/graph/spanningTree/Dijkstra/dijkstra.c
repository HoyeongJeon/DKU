#include <stdio.h>
#include "dijkstra.h"
#include "graphG.h"

// 최소 거리를 갖는 다음 정점을 찾는 연산
int nextVertex(int n) { // n은 그래프 내의 정점 수
    int i, min, minPos; // i = 반복문을 위한 인덱스 , min = 현재까지 발견된 최소 거리 저장, minPos = 최소 거리를 갖는 정점의 인덱스 저장 (초기 -1)
    min = INF;
    minPos = -1;
    for(i = 0; i < n; i++) {
        if((distance[i] < min) && !S[i]) { // 현재 정점 'i'의 거리가 'min' 보다 작고, 정점 i를 아직 방문하지 않았으면 현재 정점 'i'가 최소 거리를 갖는 다음 정점이 됨
            min = distance[i];
            minPos = i;
        }
    }
    // 최소 거리를 갖는 정점의 인덱스 반환. 만약 모든 정점이 방문되었거나, 방문되지 않은 정점 중 최소 거리가 무한대인 경우 -1 반환
    return minPos; 
}

// 최단 경로를 구하는 과정을 출력하는 연산
int printStep(int step) { // step = 현재 단계를 나타내는 인수
    int i; // 반복문에서 사용할 인덱스 변수 'i'
    printf("\n %3d 단계: S={", step); // 현재 단계 출력
    
    for(i = 0; i < MAX_VERTICES; i++) { // 정점만큼 반복하면서
        if(S[i] == TRUE) { // 해당 정점이 'S' 집합에 포함되어 있는지 확인
            printf("%3c", i + 65);
        }
    }

    if(step <= 1) printf(" } \t\t\t");
    else if (step < 4) printf(" } \t\t");
    else printf(" } \t");

    printf(" distance: [ ");

    for(i = 0; i < MAX_VERTICES; i++) { // 정점만큼 반복
        if(distance[i] == INF) {
            printf("%4s", "*");
        } else {
            printf("%4d", distance[i]);
        }
    }

    printf("%4c", ']');
    return ++step;
}

void Dijkstra_shortestPath(int start, int n) { // 시작정점 start에서 그래프의 'n'개의 정점까지 최단 경로를 찾는 함수
    int i , u , w, step = 0;    // i = 반복문을 위한 인덱스 변수, u = 최단 경로를 찾기 위해 선택된 정점 , w = 인접한 정점 , step = 현재 단계를 나타내는 변수로 초기값 0

    for(i = 0; i < n; i++) {
        distance[i] = weight[start][i]; // distance[i] = 시작지점에서 해당 정점까지 길이 저장
        S[i] = FALSE; // 방문여부를 나타내는데 초기엔 전부 FALSE로 설정
    }
    
    S[start] = TRUE;        // 시작 정점을 집합 S에 추가
    distance[start] = 0;    // 시작 정점의 최단 경로를 0으로 설정

    step = printStep(0); // 현재 단계 출력

    for(i = 0; i < n - 1; i++) { // n-1번 반복하여 모든 정점에 대해 최단 경로를 찾는다. 시작 정점은 이미 처리했으므로, n-1번 반복
        u = nextVertex(n);  // 아직 방문하지 않은 정점 중 최단 경로를 만드는 다음 정점 u 찾기
        S[u] = TRUE; // 방문 표시
        for(w = 0; w < n; w++) { // 모든 정점 'w'에 대해 
            if(!S[w]) { // 아직 집합 'S'에 포함되지 않음 정점 검사
                if(distance[u] + weight[u][w] < distance[w]) { // 정점 'u'를 통해 정점 'w'로 가는 경로가 현재 알고 있는 경로보다 짧으면 'distance[w]' 갱신
                    distance[w] = distance[u] + weight[u][w]; 
                }
            }
        }
        step = printStep(step); // 단계가 끝날 때마다 'printStep(step)'을 호출하여 현재 상태 출력
    }
}