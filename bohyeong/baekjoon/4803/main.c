	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int visited[501];
	int arr[501][501];
	int flag = 0; int count = 0;
	int point, dis;
	int gan = 0; 
	int jung = 0;

	void dfs(int num){
		visited[num] = 1;
		
		for (int i = 1; i <= point; i++) {
		

			if (arr[num][i] == 1 && !visited[i]) {//길이 있고 방문하지않았다면
				gan++;
				jung++;
				dfs(i);
			}
			else if (arr[num][i] == 1) {
				gan++;
			}
		}
	}

	void init_arr() {
		for (int i = 0; i < 501; i++) {
			for (int j = 0; j < 501; j++) {
				arr[i][j] = 0;
			}
			visited[i] = 0;
		}
		count = 0;
		flag = 1;
		
	}

	int main() {
		int c = 1;
		int a, b;

			while (1) {
			init_arr();
			scanf("%d %d", &point, &dis);
		
			if (!point && !dis) return 0;
		
			for (int i = 0; i < dis; i++) {
				scanf("%d %d", &a, &b);
				arr[a][b] = 1;
				arr[b][a] = 1;
		
			}

		 
				for (int i = 1; i <= point; i++) {
					if (!visited[i]) {
						jung = 1; gan = 0;
						dfs(i);
						if (gan / 2 == jung - 1) {
							flag = 0;
							count++;
						}
					}
				}
		
		
			switch (flag)
			{
			 case 0: {
				if (count!=1) {
					printf("Case %d: A forest of %d trees.\n", c++, count);
					break;
				}
				else {
					printf("Case %d: There is one tree.\n", c++);
					break;
				}
			 }
			 case 1: {
				printf("Case %d: No trees.\n",c++);
				break;
			 }

			}
		}
		return 0;
	}