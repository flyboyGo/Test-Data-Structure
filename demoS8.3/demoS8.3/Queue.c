#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化函数实现
void QueueInit(struct Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//销毁函数实现
void QueueDestory(struct Queue* pq)
{
	assert(pq);
	struct QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		struct QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//判断队列是否为空函数实现
int QueueEmpty(struct Queue* pq)
{
	assert(pq);
	return pq->head == NULL ? 1 : 0;
}

//入队函数实现
void QueuePush(struct Queue* pq, QDataType x)
{
	assert(pq);
	struct QueueNode* newnode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//出队函数实现
void QueuePop(struct Queue* pq)
{
	assert(pq);
	assert(pq->head);
	struct QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	//只有一个节点,删除后,队尾指针指向空
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

//取队头元素实现
QDataType QueueFront(struct Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//取队尾元素实现
QDataType QueueBack(struct Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

//求队列元素个数函数实现
int QueueSize(struct Queue* pq)
{
	assert(pq);
	struct QueueNode* cur = pq->head;
	int count = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}