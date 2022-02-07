#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct tree* treePointer;
typedef struct tree
{
	int node;
	treePointer llink;
	treePointer rlink;
}tree;
treePointer root;
treePointer tree_list[27];
void make_node();
int cnt;
void input(int parent, int left, int right);
void preorder(treePointer tmp);
void inorder(treePointer tmp);
void postorder(treePointer tmp);
int main()
{
	int size;
	char parent, left, right;
	scanf("%d ", &size);
	for (int k = 1; k <= size; k++)
	{
		make_node();
	}
	for (int i = 0; i < size; i++)
	{
		scanf("%c %c %c ", &parent, &left, &right);
		input(parent-64, left-64, right-64);
	}
	preorder(tree_list[1]);
	printf("\n");
	inorder(tree_list[1]);
	printf("\n");
	postorder(tree_list[1]);
	return 0;
}
void input(int parent, int left, int right)
{
	if (left != -51)
		tree_list[parent]->llink = tree_list[left];
	if (right != -51)
		tree_list[parent]->rlink = tree_list[right];
}
void make_node()
{
	treePointer tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->node = ++cnt;
	tmp->llink = NULL;
	tmp->rlink = NULL;
	tree_list[cnt] = tmp;
}
void inorder(treePointer tmp)
{

	if (!tmp)
		return;
	inorder(tmp->llink);
	printf("%c", tmp->node + 64);
	inorder(tmp->rlink);
}
void preorder(treePointer tmp)
{

	if (!tmp)
		return;
	printf("%c", tmp->node + 64);
	preorder(tmp->llink);
	preorder(tmp->rlink);
}
void postorder(treePointer tmp)
{

	if (!tmp)
		return;
	postorder(tmp->llink);
	postorder(tmp->rlink);
	printf("%c", tmp->node + 64);
}