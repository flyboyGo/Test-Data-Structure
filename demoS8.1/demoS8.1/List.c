#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//初始化函数实现
struct ListNode* ListInit()
{
	//哨兵位头节点
	struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//打印函数声明
void ListPrintf(struct ListNode* phead)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//查找函数实现
struct ListNode* ListFind(struct ListNode* phead, int x)
{
	assert(phead);

	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//销毁函数实现
void ListDestory(struct ListNode* phead)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}

//插入函数实现(pos位置之前插入)
void ListInsert(struct ListNode* pos, int x)
{
	assert(pos);
	struct ListNode* posPrev = pos->prev;
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data = x;

	posPrev->next = newnode;
	newnode->prev = posPrev;

	newnode->next = pos;
	pos->prev = newnode;
}

//删除函数实现(将pos删除)
void ListErase(struct ListNode* pos)
{
	assert(pos);
	struct ListNode* posPrev = pos->prev;
	struct ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//尾插函数实现
void ListPushBack(struct ListNode* phead, int x)
{
	assert(phead);
	struct ListNode* tail = phead->prev;
	//生成新节点,加载数据
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data = x;

	//插入新节点
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//等价于
	//ListInsert(phead, x);
}

//尾删函数实现
void ListPopBack(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	// struct ListNode* tail = phead->prev;
	// struct ListNode* taiiPrev = tail->prev;
	// free(tail);

	// phead->prev = taiiPrev;
	// taiiPrev->next = phead;

	//等价于
	ListErase(phead->prev);
}

//头插函数实现
void ListPushFront(struct ListNode* phead, int x)
{
	assert(phead);
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* next = phead->next;

	newnode->data = x;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;

	//等价于
	//ListInsert(phead->next,  x)
}

//头删函数实现
void ListPopFront(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	// struct ListNode* next = phead->next;
	// struct ListNode* nextNext = next->next;

	// free(next);

	// phead->next = nextNext;
	// nextNext->prev = phead;

	//等价于
	ListErase(phead->next);
}
