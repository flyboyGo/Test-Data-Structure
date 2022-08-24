#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int QDataType;

struct QueueNode 
{
	QDataType data;
	struct QueueNode* next;
};

struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

//��ʼ����������
void QueueInit(struct Queue* pq);

//���ٺ�������
void QueueDestory(struct Queue* pq);

//��Ӻ�������
void QueuePush(struct Queue* pq, QDataType x);

//���Ӻ�������
void QueuePop(struct Queue* pq);

//ȡ��βԪ������
QDataType QueueFront(struct Queue* pq);

//ȡ��βԪ������
QDataType QueueBack(struct Queue* pq);

//�����Ԫ�ظ�����������
int QueueSize(struct Queue* pq);

//�ж϶����Ƿ�Ϊ�պ�������
int QueueEmpty(struct Queue* pq);
