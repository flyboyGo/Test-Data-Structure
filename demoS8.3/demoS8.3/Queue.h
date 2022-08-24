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

//初始化函数声明
void QueueInit(struct Queue* pq);

//销毁函数声明
void QueueDestory(struct Queue* pq);

//入队函数声明
void QueuePush(struct Queue* pq, QDataType x);

//出队函数声明
void QueuePop(struct Queue* pq);

//取队尾元素声明
QDataType QueueFront(struct Queue* pq);

//取队尾元素声明
QDataType QueueBack(struct Queue* pq);

//求队列元素个数函数声明
int QueueSize(struct Queue* pq);

//判断队列是否为空函数声明
int QueueEmpty(struct Queue* pq);
