#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 400001  // �������� �𸣰����� �ִ� ���̸� �̸�ŭ�߾������ -> ���ϸ� insufficient ������

char p[MAX];
int arr[100001];
//char temp[600000];

int front, rear = 0;

//���ڿ��״�� ���ڸ� ���������ϸ� 1���ڸ� ���ڴ� �����ϳ� ���� �ڸ����ں��� ©���� ������ �̷��� �ϸ� ������ ���.
//R �Ҷ� ��¥ �迭�� �Ųٷ� �Ϸ����ϸ� �ð����⵵ ���̴�,, �׷��⿡ �ٲٴ� ������ ���� �� ó��!

void init_char(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = '\0';
        i++;
    }
    return;
}

void init_int(int* s) {
    int i = 0;
    while (s[i] != 0) {
        s[i] = 0;
        i++;
    }
    return;
} // �迭 �ʱ�ȭ���ִ°� 

int main() {

    int reverse, i;
    int flag = 0;
    int tc = 0, n = 0;
    int count = 0;
    scanf("%d", &tc);
    char c;
    int num = 0;

    while (tc--) { // �� �� ��������
        flag = 0, count = 0;
        reverse = 0;
        front = 0;
        init_char(&p);
        init_int(&arr);
        // init_char(&temp); 
        scanf("%s", p); //�Լ� ����
        scanf("%d\n", &n); // �迭 ������
        scanf("%c", &c); // "[" ����  

        if (n != 0) {
            for (int j = 0; j < n; j++)
            {
                scanf("%d%c", &num, &c); // ���ڶ� , ] ����
                arr[count++] = num;
            }
        }

        else
            scanf("%c%c", &c, &c);

        //scanf("%s", temp); // ó���� ���ڿ��� �� �ް� ���߿� ���ڸ� ������ �ϴٰ� �ʹ� ���� ��ȸ 
        //for (int i = 0; i < 2 * n + 1; i++) {
        //    if (temp[i] != '[' && temp[i] != ']' && temp[i] != ',') {
        //        arr[count++] = temp[i];
        //        //   printf("[%c]", temp[i]);
        //    }
        //}
       // rear = count-1;
        rear = (count != 0) ? count - 1 : 0; //���׿����� : (���ǹ�) ? ���̸� : �����̸�


        i = 0;
        while (p[i] != '\0') {
            if (p[i] == 'R') { //reverse�Ϸ����Ҷ�
                reverse++;
            }
            else { // 'D' ��� �Ҷ�

        //       printf("front: %d, rear:%d\n", front, rear);
                if (!count) {
                    flag = 1;
                }

                else if (reverse % 2 == 0) {
                    front++;
                    count--;
                }
                else {
                    rear--;
                    count--;
                }
            }
            i++;
        }

        if (flag) {
            printf("error\n");
        }
        else if (!count) { //flag���� ������������� �� �迭�϶� 
            printf("[]\n");
        }
        else if (!flag) {
            printf("[");
            /*for (int i = 0; i < n-1; i++) {
                printf("%c,", arr[i]);
            }
            printf("%c]\n", arr[n - 1]);*/
            if (reverse % 2 == 0) {
                for (int i = front; i < rear; i++) {
                    printf("%d,", arr[i]);
                }
                printf("%d]\n", arr[rear]);

            }
            else {
                while (rear - front != 0) {
                    printf("%d,", arr[rear]);
                    rear--;
                }
                printf("%d]\n", arr[front]);
            }

        }


    }

    return 0;
}