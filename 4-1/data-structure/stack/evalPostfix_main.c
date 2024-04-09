#include <stdio.h>
#include "stackL.h"
#include "evalPostfix.h"

int main(void) {
    int result;
    char * express = "35*62/-";
    char * infix = "((3*5)-(6/2))";
    char * postfix;
    
    postfix = infix_to_postfix(infix);
    printf("중위 표기식 : %s\n", infix);
    printf("후위 표기식 : %s\n", postfix);
    // printf("후위 표기식 : %s\n", express);

    // result = evalPostfix(express);
    // printf("결과 값 : %d\n", result);
    getchar();
    
    return 0;
}