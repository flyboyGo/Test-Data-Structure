#define _CRT_SECURE_NO_WARNINGS 1
#define DataType int
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//使用两个栈实现队列的功能效果
typedef struct Stack
{
	DataType* data;
	int top;
	int capacity;
}Stack;

typedef struct MyStack
{
	Stack pushST;
	Stack popST;
}MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->popST);
	StackInit(&q->pushST);

	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	assert(obj);
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj)
{
	//如果popST中没有数据,将psuhST的数据导过来
	//popST中的数据就符合先进先出的规律
	assert(obj);
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}

	}

	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj)
{
	//如果popST中没有数据,将psuhST的数据导过来
	//popST中的数据就符合先进先出的规律
	assert(obj);
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}

	}
	return StackTop(&obj->popST);
}

int myQueueEmpty(MyQueue* obj)
{
	assert(obj);
	return  StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestory(&obj->popST);
	StackDestory(&obj->pushST);
	free(obj);
}

// int main()
// {
// 	MyQueue* mq = myQueueCreate();
// 	myQueuePush(mq, 1);
// 	myQueuePush(mq, 2);
// 	myQueuePush(mq, 3);
// 	myQueuePush(mq, 4);
// 	myQueuePush(mq, 5);
// 	myQueuePop(mq);
// 	myQueuePop(mq);
// 	printf("%d\n", myQueuePeek(mq));
// 	myQueueFree(mq);
// 	return 0;
// }