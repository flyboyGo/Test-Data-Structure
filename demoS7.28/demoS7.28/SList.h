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


//��ӡ��������
void SListPrint(SLNode* phead);

//β�庯������
void SListPushBack(SLNode** phead, SLDataType x);