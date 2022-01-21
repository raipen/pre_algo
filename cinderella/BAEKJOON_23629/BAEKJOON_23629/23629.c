#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_STR 4
#define MAX_STR 1000


typedef enum {
	EQ,
	PLUS,
	MINUS,
	MULTIPLE,
	DIV,
	MOD
}Opr;

typedef enum {
	STATE_NUM,
	STATE_OPR
}STATE;

char* CharNumber[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int BufferPointer = 0;

char Buffer[MAX_STR - 1];

int CharToNum(char*);

int main(void){
	char str[MAX_STR];
	gets(str);

	//예외처리
	if (!str) exit(1);
	str[strlen(str)] = '\0';
	if (strlen(str) < MIN_STR || strlen(str) > MAX_STR) exit(2);

	int i, idx = 0;
	STATE StrState = STATE_NUM;

	while (BufferPointer != strlen(str)) {
		i = CharToNum(str + BufferPointer);

		if (i == -1) {
			if (StrState == STATE_OPR){
				printf("Madness!");
				return -1;
			}
			Buffer[idx++] = str[BufferPointer++];
			StrState = STATE_OPR;
			continue;
		}
		StrState = STATE_NUM;
		Buffer[idx++] = '0' + i;
	}
	printf("%s", Buffer);

}
int CharToNum(char* obj) {
	for (int i = 0; i < 10; i++) {
		if (!strncmp(obj, CharNumber[i], strlen(CharNumber[i]))) {
			BufferPointer += strlen(CharNumber[i]);
			return i;
		}
	}
	return -1;
}