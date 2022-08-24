#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void Test()
{
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n", QueueSize(&q));
	QueuePop(&q);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);
}

int main()
{
	Test();
	return 0;
}