#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include "Queue.h"

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* rigth;
	BTDataType data;
}BTNode;

//前序遍历(先序遍历、先根)
void PrevOrder(BTNode * root)
{
	if (root == NULL)
	{
		printf(" NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->rigth);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf(" NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->rigth);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf(" NULL ");
		return;
	}
	InOrder(root->left);
	InOrder(root->rigth);
	printf("%c ", root->data);
}

//节点的个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->left) + TreeSize(root->rigth);
	}

}

//叶子节点的个数
int TreeLeafSizePlus(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->left == NULL && root->rigth == NULL)
		{
			return 1;
		}
		else
		{
			return  TreeLeafSizePlus(root->left) + TreeLeafSizePlus(root->rigth);
		}
	}
}

//二叉树的最大深度
int TreeMaxDeapth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int maxLeft = TreeMaxDeapth(root->left), maxRight = TreeMaxDeapth(root->rigth);
		if ( maxLeft> maxRight )
		{
			return 1 + maxLeft;
		}
		else
		{
			return 1 + maxRight;
		} 
	}
}
 
//二叉树的层序遍历
void LevelOrder(BTNode* root)
{
	//核心思路:上一层节点出的时候带下一层节点进
	Queue q;
	QueueInit(&q);
	if (root!= NULL)
	{
		QueuePush(&q, root);
	}	

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->rigth)
		{
			QueuePush(&q, front->rigth);
		}
	}
	printf("\n");
	QueueDestory(&q);
}
 
//平衡二叉树
int TreeIsBalanced(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		int leftDepth = TreeMaxDeapth(root->left);
		int rightDepth = TreeMaxDeapth(root->rigth);

		return abs(leftDepth - rightDepth) < 2 
			       && TreeIsBalanced(root->left) 
			       && TreeIsBalanced(root->rigth);
	}
}

//销毁二叉树
int TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		TreeDestory(root->left);
		TreeDestory(root->rigth);
		free(root);
		root = NULL;
	}
}

//根据先序字符串建立对应的二叉树
BTNode* TreeCreate(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	else
	{
		BTNode* root = malloc(sizeof(BTNode));
		if (root == NULL)
		{
			printf("malloc fail\n");
			exit(-1);
		}

		root->data = str[*pi];
		++(*pi);
		root->left = TreeCreate(str, pi);
		root->rigth = TreeCreate(str, pi);
		return root;
	}
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';A->left = NULL;A->rigth = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';B->left = NULL;B->rigth = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';C->left = NULL;C->rigth = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';D->left = NULL;D->rigth = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';E->left = NULL;E->rigth = NULL;

	A->left = B;A->rigth = C;B->left = D;B->rigth = E;D->left = NULL;D->rigth = NULL;
	E->left = NULL;E->rigth = NULL;C->left = NULL;C->rigth = NULL;

	PrevOrder(A);printf("\n");
	InOrder(A);printf("\n");
	PostOrder(A); printf("\n");

	printf("节点数=%d\n", TreeSize(A));
	printf("叶子数=%d\n",TreeLeafSizePlus(A));

	LevelOrder(A);

	printf("树的深度为=%d\n", TreeMaxDeapth(A));

	printf("二叉树是否平衡:%d\n", TreeIsBalanced(A));

	char tree[] = "abc##de#g##f###";
	int i = 0;
	BTNode* newTree = TreeCreate(tree, &i);
	InOrder(newTree);

	return 0;
}