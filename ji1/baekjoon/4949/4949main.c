#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/// <summary>
/// �� �ǹ� ���� ���� ������
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
/// ���� ���� ���ڿ����� Ȯ���ϴ� �Լ�
/// </summary>
/// <param name="str">Ȯ���� ���ڿ�</param>
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
    char str[101]; //�ִ� 100����+'\0' �� �� 101ĭ �ʿ�
    while (scanf("%[^\n]%*c", str) && strcmp(str, "."))    // '\n'�� �ƴҶ����� str�� �����ϰ� '\n'�� %*c�� ���ۿ��� ���� + str�� "."�� ��� ����
        printf("%s\n", isBalanced(str) ? "yes" : "no");   //isBalanced üũ
    return 0;
}