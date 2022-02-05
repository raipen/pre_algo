#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
int size, sum;
int sol;
int max;
int mid;

typedef struct g_node{
	int ver;
	int wei;
	struct g_node* next;
}g_node;

g_node* adj_list[MAX];

void init_graph() {
	for (int i = 0; i < MAX; i++) {
		adj_list[i] = NULL;
	}
}

void insert_node(int v, int e, int w) {
	g_node* temp = (g_node*)malloc(sizeof(g_node));
	temp->ver = e; temp->wei = w;
	temp->next = adj_list[v];
	adj_list[v] = temp;
}

void print_list() {
	g_node* curr;
	for (int i = 1; i <= size; i++) {
		curr = adj_list[i];
		printf("정점 %d:", i);
		while (curr != NULL) {
			printf("간선- %d 가중치- %d ->", curr->ver, curr->wei);
			curr = curr->next;
		}
		printf("\n");
	}
}

void real_max(int n) {
	if (max < n) {
		max = n;
	}
}

void dfs(int i, int post, int aa) {
	g_node* curr;
	int wei = 0;
	int next = 0; int count = 0;
	curr = adj_list[i];

	//if (curr->ver == post) return;
	if (aa > max) {
		sol = aa;
		mid = i;
	//	printf("mid:%d\n", i);
	}
		
	while (curr != NULL) {
		if ( curr->ver != post) {
			dfs(curr->ver, i, aa+ curr->wei);
		}
		curr = curr->next;
	}

	real_max(aa);

		//dfs(next, i);

}

/*void dfs(int i, int post, int aa) {
	g_node* curr;
	int wei = 0;
	int next = 0; int count = 0;
	curr = adj_list[i];
	while (curr != NULL) {
		if (wei < curr->wei && curr->ver != post) {
			wei = curr->wei;
			next = curr->ver;
		}
		curr = curr->next;
	}
	sum += wei;
	if (aa < sum) {
		sol = sum;
	}
	if (!next) return;
	for (int k = 1; k <= arr[i]; k++) {
		dfs(k, i, sum);
	}

	//dfs(next, i);

}*/


int find_dia(){
	int sol = 0;
	/*for (int i = 1; i <= size; i++) {
		max = 0;
		dfs(i, 0, 0);
		if (sol <= max) {
			sol = max;
		}
	}*/
	max = 0;
	dfs(1, 0, 0);
	sol = max;
	if (mid != 1) {
	//	printf("mid: %d", mid);
		max = 0;
		dfs(mid, 0, 0);
		if (max >= sol) {
			sol = max;
		}
	}
	printf("%d\n", sol);
}

int main() {
	int vertex;
	int e, w, flag;
	init_graph();
	scanf("%d", &size);
	int num = size;

	while (num--) {
	
		scanf("%d", &vertex);
		scanf("%d", &e);
		while (e != -1) {
	
			scanf("%d", &w);
			insert_node(vertex, e, w);
			scanf("%d", &e);
		}

	}

	//print_list();

	find_dia();

	return 0;
}