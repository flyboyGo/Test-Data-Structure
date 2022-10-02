#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//打印函数声明实现
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

//尾插函数实现
void SListPushBack(SLNode** pphead, SLDataType x)
{
	//生成新的节点
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode != NULL);
	//新节点装填数据
	newnode->data = x;
	newnode->next = NULL;
	
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//新节点装填数据
		newnode->data = x;
		newnode->next = NULL;
		//插入尾节点
		tail->next = newnode;
	}
}