#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

struct ListNode
{
	int data;
	struct ListNode* prev;
	struct ListNode* next;
};

//初始化函数声明
struct ListNode* ListInit();

//打印函数声明
void ListPrintf(struct ListNode* phead);

//销毁函数声明
void ListDestory(struct ListNode* phead);

//尾插函数声明
void ListPushBack(struct ListNode* phead, int x);

//尾删函数声明
void ListPopBack(struct ListNode* phead);

//头插函数声明
void ListPushFront(struct ListNode* phead, int x);

//头删函数声明
void ListPopFront(struct ListNode* phead);

//查找函数声明
struct ListNode* ListFind(struct ListNode* phead, int x);

//插入函数声明
void ListInsert(struct ListNode* pos, int x);

//删除函数声明
void ListErase(struct ListNode* pos);
