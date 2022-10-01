#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define SLDataType int

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;


//��ӡ��������
void SListPrint(const SLNode* pphead);

//β�庯������
void SListPushBack(SLNode** pphead, SLDataType x);

//ͷ�庯������
void SListPushFront(SLNode** pphead, SLDataType x);

//βɾ��������
void SListPopBack(SLNode** pphead);

//ͷɾ��������
void SListPopFront(SLNode** pphead);

//���Һ�������
SLNode* SListFind(SLNode* pphead, SLDataType x);

//���뺯������(Ĭ����posλ��֮ǰ����һ���ڵ�)
void SListInsert(SLNode** pphead, int pos, SLDataType x);
void SListInsertPlus(SLNode** pphead, SLNode* pos, SLDataType x);

//���뺯��ʵ��(Ĭ����posλ��֮����뺯��)
void SListInsertAfter(SLNode** pphead, SLNode* pos, SLDataType x);

//ɾ����������
void SListErase(SLNode** pphead, int pos);
void SListErasePlus(SLNode** pphead, SLNode* pos);
void SListEraseAfter(SLNode** pphead, SLNode* pos);

//���ٺ�������
void SListDestory(SLNode** pphead);
