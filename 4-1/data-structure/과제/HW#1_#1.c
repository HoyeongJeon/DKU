#include <stdio.h>

#define SIZE 9

int main(void) {
  int A[SIZE] = {2, -1, 3, 3, 2, -2, 1, 3, 1};
  int B[SIZE] = {1, 2, -1, 2, 3, 1, -2, 4, 3};

  // 행렬 곱
  int C[SIZE] = {};
  for (int i = 0; i < 3; i++) {   // C의 행
    for (int j = 0; j < 3; j++) { // C의 열
      for (int k = 0; k < 3; k++) {
        C[i * 3 + j] += A[i * 3 + k] * B[k * 3 + j];
      }
    }
  }

  // 결과 출력
  for (int i = 0; i < 9; i++) {
    printf("%d ", C[i]);
    if ((i + 1) % 3 == 0)
      printf("\n");
  }
  return 0;
}
