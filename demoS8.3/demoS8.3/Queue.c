#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ������ʵ��
void QueueInit(struct Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

//���ٺ���ʵ��
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

//�ж϶����Ƿ�Ϊ�պ���ʵ��
int QueueEmpty(struct Queue* pq)
{
	assert(pq);
	return pq->head == NULL ? 1 : 0;
}

//��Ӻ���ʵ��
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

//���Ӻ���ʵ��
void QueuePop(struct Queue* pq)
{
	assert(pq);
	assert(pq->head);
	struct QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	//ֻ��һ���ڵ�,ɾ����,��βָ��ָ���
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

//ȡ��ͷԪ��ʵ��
QDataType QueueFront(struct Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

//ȡ��βԪ��ʵ��
QDataType QueueBack(struct Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

//�����Ԫ�ظ�������ʵ��
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