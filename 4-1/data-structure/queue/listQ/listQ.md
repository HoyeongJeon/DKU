# 큐의 이해

## 1. 큐의 개념과 구조

- 큐는 먼저 넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조로 저장하는 자료구조이다.

<img width="557" alt="image" src="https://github.com/HoyeongJeon/DKU/assets/78394999/ea8fc829-74de-4925-8e4d-08e074f0a5f7">

- 큐의 연산

  - Enqueue : 큐에 데이터를 넣는 작업
  - Dequeue : 큐에서 데이터를 꺼내는 작업

- 큐의 추상 자료형
  - 데이터 : 0개 이상의 원소를 가지는 유한 순서 리스트
    - item : 큐에 저장되는 원소
    - front : 큐의 첫번째 원소
    - rear : 큐의 마지막 원소
  - 연산
    - createQueue() : 공백 큐를 생성
    - isQueueEmpty(Q) : 큐가 공백인지 검사
    - isQueueFull(Q) : 큐가 포화인지 검사
    - Enqueue(Q, item) : 큐의 rear에 원소 item을 추가
    - Dequeue(Q) : 큐의 front에 있는 원소 item을 삭제하고 반환
    - peekQueue(Q) : 큐의 front에 있는 item을 반환
