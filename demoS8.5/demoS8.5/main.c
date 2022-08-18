#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define DataType int

typedef struct CirQueue
{
	DataType* data;
	int front;
	int rear;
	int size;
}CirQueue;

CirQueue* myCirQueueInit(int k)
{
	CirQueue* cq = (CirQueue*)malloc(sizeof(CirQueue));
	cq->data = (int*)malloc(sizeof(int*) * (k + 1));
	cq->front = cq->rear = 0;
	cq->size = k;
	return cq;
}

int myCirQueueIsEmpty(CirQueue* cq)
{
	assert(cq);
	return (cq->front == cq->rear ? 1 : 0);
}

int myCirQueueIsFull(CirQueue* cq)
{
	assert(cq);
	return (cq->rear + 1) % (cq->size + 1) == cq->front;
}

void myCirQueueEnQueue(CirQueue* cq, DataType x)
{
	assert(cq);
	if (myCirQueueIsFull(cq))
	{
		printf("CirQueue is Full!\n");
		exit(-1);
	}
	else
	{
		cq->data[cq->rear] = x;
		cq->rear = (cq->rear + 1) % (cq->size + 1);
	}
}

void myCirQueueDeQueue(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmpty(cq))
	{
		printf("CirQueue is empty!\n");
		exit(-1);
	}
	else
	{
		cq->front = (cq->front + 1) % (cq->size + 1);
	}
}

int myCirQueueFront(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmpty(cq))
	{
		printf("CirQueue is empty!\n");
		exit(-1);
	}
	else
	{
		return cq->data[cq->front];
	}

}

int myCirQueueRear(CirQueue* cq)
{
	assert(cq);
	if (myCirQueueIsEmpty(cq))
	{
		printf("CirQueue is empty!\n");
		exit(-1);
	}
	else
	{
		//if (cq->rear == 0)
		//{
		//	return cq->data[cq->size];
		//}
		//else
		//{
		//	return cq->data[cq->rear - 1];
		//}

		//µÈ¼ÛÓÚ
		int real = (cq->rear + cq->size) % (cq->size + 1);
		return cq->data[real];
	}

}

void myCirQueueFree(CirQueue* cq)
{
	free(cq->data);
	free(cq);
}

int myCirQueueSize(CirQueue* cq)
{
	assert(cq);
	int count = 1;
	int top = cq->front;
	while ((top + 1) % (cq->size + 1) != cq->rear)
	{
		count++;
		top++;
	}
	return count;
}

//int main()
//{
//	CirQueue* cq = myCirQueueInit(5);
//	myCirQueueEnQueue(cq, 1);
//	myCirQueueEnQueue(cq, 2);
//	myCirQueueEnQueue(cq, 3);
//	myCirQueueEnQueue(cq, 4);
//	myCirQueueEnQueue(cq, 5);
//	printf("%d\n", myCirQueueSize(cq));
//	myCirQueueDeQueue(cq);
//	printf("%d\n", myCirQueueSize(cq));
//	printf("front = %d\n", myCirQueueFront(cq));
//	printf("rear = %d\n", myCirQueueRear(cq));
//	return 0;
//}