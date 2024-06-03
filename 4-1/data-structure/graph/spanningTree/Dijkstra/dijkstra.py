n, m = map(int, input().split()) # 노드와 간선의 개수 입력받기
k = int(input()) # 시작 노드
INF = 1e8

graph = [[] for _ in range(n + 1)] # 인덱스를 1부터 사용하기 위해 n+1개의 리스트 생성

visited = [False] * (n + 1)
distance = [INF] * (n + 1)

for _ in range(m): # m개의 간선정보
    u, v, w = map(int,input().split()) # u: 출발노드 , v: 도착노드, w: 연결된 간선의 가중치
    graph[u].append((v,w))             # 거리 정보와 도착노드를 같이 입력
    
# 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드 찾기
def get_smallest_node():
    min_val = INF # 현재까지의 최소 거리 저장. 처음엔 무한대
    index = 0 # 최소 거리를 가진 노드의 인덱스 저장
    for i in range(1, n+1):
        if distance[i] < min_val and not visited[i]: # 모든 노드를 순회하며 , 방문하지 않았고 , 거리가 min_val보다 작은 노드 찾기
            min_val = distance[i]
            index = i
    return index # 최종저긍로 최소 거리를 가진 노드의 인덱스 반환

# def dijkstra(start):
#     distance[start] = 0
#     visited[start] = True
    
#     for i in graph[start]:
#         distance[i[0]] = i[1] # 시작 노드와 연결된 노드들의 거리 입력
    
#     for _ in range(n-1):
#         now = get_smallest_node() # 거리가 구해진 노드 중 가장 짧은 거리 선택
#         visited[now] = True       # 방문 처리
    
#         for j in graph[now]:
#             if distance[now] + j[1] < distance[j[0]]: # 기존의 거리보다 더 짧은 거리가 있다면
#                 distance[j[0]] = distance[now] + j[1]  

import heapq

def dijkstra_heap(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    
    while q:
        dist, now = heapq.heappop(q) # 우선순위가 가장 낮은 값(가장 작은 거리)가 나옴
        
        if distance[now] < dist: # 이미 입력되어 있는 값이 현재노드까지의 거리보다 작다면 이미 방문한 노드
            continue            
        
        for i in graph[now]: # 연결된 모든 노드 탐색
            if dist + i[1] < distance[i[0]]: # 기존에 입력된 값보다 크면
                distance[i[0]] = dist + i[1]
                heapq.heappush(q, (distance[i[0]] , i[0]))
dijkstra_heap(k)
print(distance)