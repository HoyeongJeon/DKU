# 균형 이진 탐색 트리

## 균형 이진 탐색 트리의 개념

<img width="481" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/4470ca94-e1b9-41de-a5c7-f927ba392905">

이진 탐색 트리의 경우 최소 높이를 가진 경우(a) O(log n) 시간 복잡도를 가진다. (b)와 같이 최대 높이를 가진 경우엔 O(n)이 된다.
따라서 이진 탐색 트리가 한쪽으로 치우치지 않고 균형을 이루도록 맞춰주면 탐색 성능을 높일 수 있음.
-> 이러한 원리로 이진 탐색 트리에 왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이에 대한 균형 조건을 추가하여 정의한 것이 균형 이진 탐색 트리(Balanced Binary Search Tree) 또는 균형 트리(Balanced Tree)라고 한다.

## AVL 트리의 개념과 유형

AVL 트리는 각 노드에서 왼쪽 서브 트리의 높이 hL(height of left subtree)과 오른쪽 서브 트리의 높이 hR(height of right subtree)의 차이가 1을 넘지 않는 이진 탐색 트리이다.

AVL 트리의 특징

- 왼쪽 서브 트리 < 부모 노드 < 오른쪽 서브 트리
- 각 노드의 왼쪽 서브 트리 높이와 오른쪾 서브 트리 높이의 차이(hL-hR)인 노드의 균형 인수 BF(Balance Factor)가 -1, 0, 1인 이진 탐색 트리
- 각 노드의 균형 인수로 [-1, 0, 1]의 값만 가지게 함으로써 왼쪽 서브 트리와 오른쪽 서브 트리의 균형을 항상 유지함.

균형 인수 BF는 다음 그림과 같이 각 노드에서 왼쪽 서브 트리의 높이 hL과 오른쪽 서브 트리의 높이 hR의 차이를 통해 구함.
<img width="422" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/1738e12c-fb68-4e6d-b3b8-419a85272996">

다음 그림의 이진 탐색 트리는 모든 노드가 균형 인수로 {-1, 0, 1}의 값을 가지므로 AVL 트리이다.
<img width="472" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/6f57e2e4-cf3c-4925-a96c-2e406cb7b945">

다음 그림의 이진 탐색 트리는 노드들이 균형 인수로 {-1, 0, 1} 외의 값을 가지므로 균형이 깨져 한 방향으로 치우친 비AVL 트리이다.
<img width="459" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/f416810a-c419-4998-abc9-b18c5cde123a">
