#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"
#include "evalPostfix.h"



// 전위 표기법을 후위 표기법으로 변경
char * infix_to_postfix(char* exp) {
    // exp = ((3 * 5) - (6 / 2))

    int length = strlen(exp);
    top = NULL;
    char symbol;
    char * postfix = (char*)malloc(sizeof(char) * (length + 1));
    char temp;
    int postfixIndex = 0;
    
    for(int i = 0; i < length; i++) {
        symbol = exp[i];
        if(symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '(' && symbol != ')') {
        // 피연산자인 경우
        postfix[postfixIndex++] = symbol;
        } else if(symbol == '(')  {
        } else if(symbol==')') {
            temp = pop();
            postfix[postfixIndex++] = temp;
        } else {
            // 연산자인 경우
            push(symbol);
        }
    }   
    postfix[length] = '\0';
    return postfix;
}


// 후위 표기법 수식을 계산하는 함수
element evalPostfix(char* exp) {
    int opr1, opr2, value, i = 0;
    int length = strlen(exp);
    char symbol;

    top = NULL;

    for(i = 0; i < length; i++) {
        symbol = exp[i];
        if(symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
            value = symbol - '0'; // symbol은 char이므로 계산을 위해 int로 변환
            push(value);
        } else {
            opr2 = pop();
            opr1 = pop();

            switch (symbol)
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            }
        }
    }
    return pop();
}