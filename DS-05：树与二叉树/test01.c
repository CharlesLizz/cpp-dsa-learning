#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
typedef int ElementType;

typedef struct TNode* Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode { /* 树结点定义 */
	ElementType Data; /* 结点数据 */
	BinTree Left;    /* 指向左子树 */
	BinTree Right;   /* 指向右子树 */
};

BinTree BuildTree(int Inorder[], int Postorder[], int N);
void PreorderTraversal(BinTree BT);

int main()
{
	BinTree T;
	int Inorder[MAXN], Postorder[MAXN], N, i;
	//中序             后序
	printf("输入结点个数\n");
	scanf("%d", &N);

	printf("输入后序遍历序列\n");
	for (i = 0;i < N;i++) scanf("%d", &Postorder[i]);

	printf("输入中序遍历序列\n");
	for (i = 0;i < N;i++) scanf("%d", &Inorder[i]);

	T = BuildTree(Inorder, Postorder, N);
	printf("Preorder:"); PreorderTraversal(T);printf("\n");
	return 0;
}

BinTree BuildTree(int Inorder[], int Postorder[], int N)
{ /* 根据中序和后序数组中的N个结点建树 */
	BinTree T;
	int p;

	if (!N) return NULL; /* 递归终止条件:空树 */

	T = (BinTree)malloc(sizeof(struct TNode));
	T->Data = Postorder[N - 1]; /* 根结点是后序最后一个 */
	T->Left = T->Right = NULL;

	for (p = 0;p < N;p++) /* 在中序里找根结点 */
		if (Inorder[p] == Postorder[N - 1]) break;

	T->Left = BuildTree(Inorder, Postorder, p);
	T->Right = BuildTree(Inorder + p + 1, Postorder + p, N - p - 1);

	return T;
}

void PreorderTraversal(BinTree T)
{
	if (T)
	{
		printf("%d ", T->Data);
		PreorderTraversal(T->Left);
		PreorderTraversal(T->Right);
	}
}