#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define DataType int

typedef struct ListNode
{
	struct ListNode* next;
	DataType data;
}ListNode;

typedef struct CirQueue
{
	ListNode* head;
	ListNode* tail;
	int size;
}CirQueue;

CirQueue* myCirQueueInitList(int k)
{
	assert(k >= 1);
	int n = k + 1;
	CirQueue* cq = (CirQueue*)malloc(sizeof(CirQueue));
	cq->size = k;
	ListNode* tmp = NULL;
	while (n)
	{
		ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
		if (n == k + 1)
		{
			cq->head = cq->tail = newnode;
			tmp = newnode;
		}
		else if (n == 1)
		{
			tmp->next = newnode;
			newnode->next = cq->head;
		}
		else
		{
			tmp->next = newnode;
			tmp = newnode;
		}
		n--;
	}
	return cq;
}

int myCirQueueIsEmptyList(CirQueue* cq)
{
	return cq->head == cq->tail;
}

int myCirQueueIsFullList(CirQueue* cq)
{
	return cq->tail->next == cq->head;
}

void myCirQueueEnQueueList(CirQueue* cq, DataType x)
{
	assert(cq);
	if (myCirQueueIsFullList(cq))
	{
		printf("myCirQueueList is full!\n");
		exit(-1);
	}
	else
	{
		cq->tail->data = x;
		cq->tail = cq->tail->next;
	}
}

void myCirQueueDeQueueList(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmptyList(cq))
	{
		printf("myCirQueue is empty!\n");
		exit(-1);
	}
	else
	{
		cq->head = cq->head->next;
	}
}

int myCirQueueFrontList(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmptyList(cq))
	{
		printf("myCirQueueList is empty!\n");
		exit(-1);
	}
	else
	{
		return cq->head->data;
	}
}

int myCirQueueRearList(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmptyList(cq))
	{
		printf("myCirQueueList is empty!\n");
		exit(-1);
	}
	else
	{
		int count = 1;
		ListNode* cur = cq->head;
		while (cur->next != cq->tail)
		{
			cur = cur->next;
			count++;
		}
		return cur->data;
	}
}

void myCirQueueFreeList(CirQueue* cq)
{
	assert(cq);
	ListNode* cur = cq->head, * next = NULL;
	int size = cq->size;
	for (int i = 0; i < size + 1; i++)
	{
		next = cur->next;
		free(cur);
		cur->next = NULL;
		cur = next;
	}
}

int myCirQueueSizeList(CirQueue* cq)
{
	assert(cq);
	int count = 1;
	ListNode* cur = cq->head;
	while (cur->next != cq->tail)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

int main()
{
	CirQueue* cq = myCirQueueInitList(5);

	printf("%d\n", myCirQueueIsEmptyList(cq));
	printf("%d\n", myCirQueueIsFullList(cq));

	myCirQueueEnQueueList(cq, 1);
	myCirQueueEnQueueList(cq, 2);
	myCirQueueEnQueueList(cq, 3);
	myCirQueueEnQueueList(cq, 4);

	printf("%d\n", myCirQueueIsEmptyList(cq));
	printf("%d\n", myCirQueueIsFullList(cq));

	myCirQueueEnQueueList(cq, 5);
	printf("%d\n", myCirQueueIsEmptyList(cq));
	printf("%d\n", myCirQueueIsFullList(cq));

	myCirQueueDeQueueList(cq);
	printf("%d\n", myCirQueueIsFullList(cq));

	printf("%d\n", myCirQueueFrontList(cq));
	printf("%d\n", myCirQueueRearList(cq));

	printf("%d\n", myCirQueueSizeList(cq));

	myCirQueueFreeList(cq);
	return 0;
}