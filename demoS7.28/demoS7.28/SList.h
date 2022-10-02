#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SLDataType int

typedef struct SListNode 
{
	SLDataType data;
	struct SListNode* next;
}SLNode;


//打印函数声明
void SListPrint(SLNode* phead);

//尾插函数声明
void SListPushBack(SLNode** phead, SLDataType x);