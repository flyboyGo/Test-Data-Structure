#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//��ʼ������ʵ��
struct ListNode* ListInit()
{
	//�ڱ�λͷ�ڵ�
	struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//��ӡ��������
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

//���Һ���ʵ��
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

//���ٺ���ʵ��
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

//���뺯��ʵ��(posλ��֮ǰ����)
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

//ɾ������ʵ��(��posɾ��)
void ListErase(struct ListNode* pos)
{
	assert(pos);
	struct ListNode* posPrev = pos->prev;
	struct ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//β�庯��ʵ��
void ListPushBack(struct ListNode* phead, int x)
{
	assert(phead);
	struct ListNode* tail = phead->prev;
	//�����½ڵ�,��������
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data = x;

	//�����½ڵ�
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//�ȼ���
	//ListInsert(phead, x);
}

//βɾ����ʵ��
void ListPopBack(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	// struct ListNode* tail = phead->prev;
	// struct ListNode* taiiPrev = tail->prev;
	// free(tail);

	// phead->prev = taiiPrev;
	// taiiPrev->next = phead;

	//�ȼ���
	ListErase(phead->prev);
}

//ͷ�庯��ʵ��
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

	//�ȼ���
	//ListInsert(phead->next,  x)
}

//ͷɾ����ʵ��
void ListPopFront(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	// struct ListNode* next = phead->next;
	// struct ListNode* nextNext = next->next;

	// free(next);

	// phead->next = nextNext;
	// nextNext->prev = phead;

	//�ȼ���
	ListErase(phead->next);
}
