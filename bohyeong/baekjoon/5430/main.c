#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 400001  // 왜인지는 모르겠지만 최대 길이를 이만큼했어야했음 -> 안하면 insufficient 오류뜸

char p[MAX];
int arr[100001];
//char temp[600000];

int front, rear = 0;

//문자열그대로 숫자를 받을려고하면 1의자리 숫자는 가능하나 십의 자리숫자부터 짤리기 때문에 이렇게 하면 오류가 뜬다.
//R 할때 진짜 배열을 거꾸로 하려고하면 시간복잡도 헬이다,, 그렇기에 바꾸는 느낌만 나는 것 처럼!

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
} // 배열 초기화해주는것 

int main() {

    int reverse, i;
    int flag = 0;
    int tc = 0, n = 0;
    int count = 0;
    scanf("%d", &tc);
    char c;
    int num = 0;

    while (tc--) { // 몇 번 돌릴껀지
        flag = 0, count = 0;
        reverse = 0;
        front = 0;
        init_char(&p);
        init_int(&arr);
        // init_char(&temp); 
        scanf("%s", p); //함수 길이
        scanf("%d\n", &n); // 배열 수길이
        scanf("%c", &c); // "[" 받음  

        if (n != 0) {
            for (int j = 0; j < n; j++)
            {
                scanf("%d%c", &num, &c); // 숫자랑 , ] 받음
                arr[count++] = num;
            }
        }

        else
            scanf("%c%c", &c, &c);

        //scanf("%s", temp); // 처음에 문자열로 다 받고 그중에 숫자를 고르려고 하다가 너무 힘들어서 선회 
        //for (int i = 0; i < 2 * n + 1; i++) {
        //    if (temp[i] != '[' && temp[i] != ']' && temp[i] != ',') {
        //        arr[count++] = temp[i];
        //        //   printf("[%c]", temp[i]);
        //    }
        //}
       // rear = count-1;
        rear = (count != 0) ? count - 1 : 0; //삼항연산자 : (조건문) ? 참이면 : 거짓이면


        i = 0;
        while (p[i] != '\0') {
            if (p[i] == 'R') { //reverse하려고할때
                reverse++;
            }
            else { // 'D' 언어 할때

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
        else if (!count) { //flag에는 위배되지않지만 빈 배열일때 
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