#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/// <summary>
/// 별 의미 없는 스택 구현부
/// </summary>
typedef char stackContents;
typedef struct {
    stackContents* s;
    int t;
}stack;

stack* newStack(int size) {
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->s = (stackContents*)malloc(sizeof(stackContents) * size);
    temp->t = 0;
    return temp;
}

int isEmpty(stack* t) {
    return t->t;
}

void push(stack* t, stackContents c) {
    t->s[t->t++] = c;
}

stackContents pop(stack* t) {
    return t->s[--(t->t)];
}

/// <summary>
/// 군형 잡힌 문자열인지 확인하는 함수
/// </summary>
/// <param name="str">확인할 문자열</param>
/// <returns>true or false</returns>

int isBalanced(char* str) {
    stack* test = newStack(100);
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
        case '(': case '[':
            push(test, str[i]);
            break;
        case ')':
            if (pop(test) != '(')
                return 0;
            break;
        case ']':
            if (pop(test) != '[')
                return 0;
            break;
        }
    }
    return !isEmpty(test);
}

int main() {
    char str[101]; //최대 100글자+'\0' 라서 총 101칸 필요
    while (scanf("%[^\n]%*c", str) && strcmp(str, "."))    // '\n'이 아닐때까지 str에 저장하고 '\n'은 %*c로 버퍼에서 제거 + str이 "."인 경우 끝냄
        printf("%s\n", isBalanced(str) ? "yes" : "no");   //isBalanced 체크
    return 0;
}