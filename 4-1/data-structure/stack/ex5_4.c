#include <stdio.h>
#include "stackL.h"
#include "evalPostfix.h"

int main(void) {
    int result;
    char * express = "35*62/-";
    printf("후위 표기식 : %s\n", express);

    result = evalPostfix(express);
    printf("결과 값 : %d\n", result);

    getchar();
    return 0;
}