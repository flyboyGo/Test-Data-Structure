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


//打印函数声明
void SListPrint(const SLNode* pphead);

//尾插函数声明
void SListPushBack(SLNode** pphead, SLDataType x);

//头插函数声明
void SListPushFront(SLNode** pphead, SLDataType x);

//尾删函数声明
void SListPopBack(SLNode** pphead);

//头删函数声明
void SListPopFront(SLNode** pphead);

//查找函数声明
SLNode* SListFind(SLNode* pphead, SLDataType x);

//插入函数声明(默认在pos位置之前插入一个节点)
void SListInsert(SLNode** pphead, int pos, SLDataType x);
void SListInsertPlus(SLNode** pphead, SLNode* pos, SLDataType x);

//插入函数实现(默认在pos位置之后插入函数)
void SListInsertAfter(SLNode** pphead, SLNode* pos, SLDataType x);

//删除函数声明
void SListErase(SLNode** pphead, int pos);
void SListErasePlus(SLNode** pphead, SLNode* pos);
void SListEraseAfter(SLNode** pphead, SLNode* pos);

//销毁函数声明
void SListDestory(SLNode** pphead);
