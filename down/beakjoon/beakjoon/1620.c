#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pokemon
{
	char name[21];
	int index;
}pokemon;

pokemon poke[100001];
pokemon poke_map[26][100002];
int main()
{
	int size,num=0,cnt=0,deca=1;
	int quest_num;
	char find[21];
	scanf("%d %d", &size, &quest_num);
	for (int i = 1; i <= size; i++)
	{
		scanf("%s", &poke[i].name);
		getchar();
		poke[i].index = i;
		poke_map[poke[i].name[0]-65][poke_map[poke[i].name[0]-65][100001].index++]=poke[i];
	}
	for (int j = 1; j <= quest_num; j++)
	{
		scanf("%s", &find);
		getchar();
		if ('0' <= find[0] && '9' >= find[0])
		{
			num = 0, deca = 1, cnt = 0;
			while (1)
			{
				if (find[cnt] == '\0')
				{
					cnt--;
					break;
				}
				cnt++;
			}
			while (1)
			{
				if (cnt < 0)
					break;
				num += (find[cnt]-48) * deca;
				cnt -= 1;
				deca *= 10;
			}
			printf("%s\n",poke[num].name);
		}
		else
		{
			for (int i = 0; i <= size; i++)
			{
				if (strcmp(poke_map[find[0]-65][i].name, find) == 0)
				{
					printf("%d\n", poke_map[find[0]-65][i].index);
					break;
				}
			}
		}
	}
	return 0;
}