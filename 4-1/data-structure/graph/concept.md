# 그래프

## 01 | 그래프의 구조

### 1. 그래프의 개념

그래프(Graph)는 원소 사이의 다:다 관계를 표현하는 비선형 자료구조
예를 들어 버스 노선도나 지하철 노선도, 인간관계를 나타내는 인맥 지도, 수도 배관에 배수 시스템, 물질의 분자 구조 등은 선형 자료구조나 트리 자료구조로 표현할 수 없다.
이런 경우에는 그래프 자료구조를 사용한다.
<img width="485" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/a81f983b-03e6-437e-88b0-906e50389fa4">

그래프는 객체르 나타내는 정점(Vertex)과 객체를 연결하는 간선(Edge)으로 구성된다.
그래프 G는 G=(V,E)로 표현한다.
여기서 V는 정점의 집합이고, E는 간선의 집합이다.
<img width="385" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/e4beea7e-f7ab-433b-aab2-cde3f2b59e62">

### 2. 그래프의 종류

그래프는 방향성과 연결 정도에 따라 여러 형태로 나뉨.

**1. 무방향 그래프(Undirected Graph)**
두 정점을 연결하는 간선에 방향이 없는 그래프
무방향 그래프에서 정점 A와 B를 연결하는 간선은 (A,B)와 (B,A)로 표현한다.
정점이 n개인 무방향 그래프의 최대 간선 수는 n(n-1)/2이다.

아래 그림의 그래프 G1과 G2는 간선에 방향이 없으므로 무방향 그래프이다.
<img width="467" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/1a1aea7b-d4df-4654-9366-2745efcdfecb">

**2. 방향 그래프(Directed Graph)**
간선에 방향이 있는 그래프, 다이그래프(DiGraph)라고도 함
방향 그래프에서 정점 A와 B를 연결하는 간선은 <A,B>로 표현한다.
A->B는 <A,B>로 표현한다.
A를 꼬리, B를 머리라고 부른다.
방향 그래프의 간선은 순서쌍으로 표현되므로 간선의 개수는 최대 n(n-1)이다.

아래 그림의 방향 그래프 G3,G4를 정점의 집합 V(G)와 간선의 집합 E(G)로 표현한 것.
<img width="467" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/257687d5-8f0f-4e0f-be48-ebbe010bdb5d">

**3. 완전 그래프(Complete Graph)**
모든 정점이 서로 연결된 그래프
최대로 많은 간선 수를 가진 그래프
완전 그래프의 정점의 개수가 n일 때, 간선의 개수는 n(n-1)/2이다.
아래 그림에서 G5는 정점의 개수가 4개인 무방향 그래프이므로, 완전 그래프가 되려면
4(4-1) / 2 = 6개의 간선이 필요하다.
G6은 정점의 개수가 4개인 방향 그래프이므로, 완전 그래프가 되려면 4(4-1) = 12개의 간선이 필요하다.
<img width="392" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/3b1a6640-2b29-4e6d-a4f9-1d816e4dfe65">

**4. 부분 그래프(Subgraph)**
원래 그래프에서 정점이나 간선을 일부만 제외하여 만든 그래프
그래프 G와 G의 부분 그래프 G'의 정점 집합과 간선 집합은 다음 조건을 만족해야 한다.
<img width="202" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/ec7890ef-2855-4ee2-a6e7-317d40b3d429">

다음 그림은 그래프 G1에 대한 부분 그래프 중 일부이다.
<img width="439" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/8c2e6bbe-022f-4e86-aa4b-e3bba673b59d">

**5. 가중 그래프(Weighted Graph)**
정점을 연결하는 간선에 가중치(Weight)를 할당한 그래프
네트워크라고도 함
<img width="390" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/2b733722-3fc1-481f-ba3f-81f454069027">

### 3. 그래프 관련 용어

그래프에서 두 정점 A와 B가 연결되어 간선 (A,B)가 있을 때 두 정점 A와 B를 인접(Adjacent)하다고 하며, 간선 (A,B)는 정점 A와 B에 부속(Incident)되어 있다고 한다.

아래 무방향 그래프 G1에서 정점 A와 B는 인접하며, 간선 (A,B)는 정점 A와 B에 부속되어 있다.
<img width="384" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/88c6335e-1eb0-41a8-91e9-710bdaaae63e">

정점에 부속되어 있는 간선의 개수를 정점의 차수(Degree)라고 한다.
따라서 정점 A의 차수는 2이고, 정점 B의 차수는 3이다.

**방향 그래프** 에선 정점에 부속된 간선 방향에 따라 진입 차수(In-Degree)와 진출 차수(Out-Degree)로 나뉜다.
정점을 머리로 하는 간선 수는 진입 차수가 되고, 정점을 꼬리로 하는 간선 수는 진출 차수가 된다.
<img width="379" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/5a4b876a-a6b8-441f-968a-df9bc9c93ffd">

그래프에서 간선을 따라갈 수 있는 길을 순서대로 나열한 것, 즉 정점 A에서 정점 B까지 간선으로 연결된 정점을 순서대로 나열한 리스트를 정점 A에서 B까지의 **경로(Path)**라고 한다.
경로의 길이는 경로를 구성하는 간선의 수로 정의한다.

위 그림의 무방향 그래프 G1에서 정점 A에서 C까지는 A-B-C, A-B-D-C, A-D-B-C 경로 등이 있다.
여기서 A-D-B-C는 간선이 (A,D), (D,B), (B,C)로 3개이므로 길이가 3이다.

방향 그래프 G3에서 정점 A에서 C까지의 경로는 A-B-C이고, 간선 <A,B> , <B,C>로 2개이므로 길이가 2이다.

모두 다른 정점으로 구성된 경로를 **단순 경로(Simple Path)**라고 한다.
그래프 G1에서 정점 A에서 C까지의 경로 A-B-C는 단순 경로이고, 경로 A-B-D-A-B-C는 단순 경로가 아니다.

단순 경로에서 시작 정점과 종료 정점이 같은 경우를 **사이클(Cycle)**이라고 한다.

방향 그래프이면서 사이클이 없는 그래프를 **DAG(Directed Acyclic Graph)**라고 한다.

그래프에서 두 정점 A에서 B까지의 경로가 있으면 정점 A와 B는 **연결되어 있다(Connected)**고 한다.

아래 그림에서 a와 같이 모든 정점 쌍이 연결되어 있으면 **연결 그래프(Connected Graph)**라고 한다.

- 트리는 사이클이 없는 연결 그래프이다.

아래 그림에서 b와 같이 연결 그래프가 아닌 그래프를 **비연결 그래프(Disconnected Graph)**라고 한다.
<img width="353" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/86e183aa-dff5-4c01-b580-166a4a144b3d">

**연결 요소(Connected Component)**는 연결 그래프에서 정점의 부분 집합으로서, 그 부분 집합에 속한 모든 정점 쌍이 연결되어 있는 것을 말한다.

### 4. 그래프의 추상 자료형

<img width="475" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/43cbbd0c-f3b4-4b89-9093-2f88ecefe3a2">

## 02 | 그래프의 구현

그래프를 구현할 땐 순차 자료구조를 이용하는 2차원 배열의 인접 행렬(Adjacent Matrix) 방법과 연결 자료구조인 연결 리스트를 사용하는 인접 리스트(Adjacent List) 방법이 있다.

### 1. 순차 자료구조를 이용한 그래프의 구현 : 인접 행렬(Adjacent Matrix)

그래프에선 두 정점을 연결한 간선의 유무를 행렬로 저장하기 위해서 정점 수에 대한 정방 행렬을 사용한다.
정점을 n개 가진 그래프는 n x n 정방 행렬을 사용하는데, 두 정점이 인접하면 1, 아니면 0으로 표시한다.
<img width="394" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/c2af0eda-7367-46f1-ba56-d0f5d2cf3cf6">
