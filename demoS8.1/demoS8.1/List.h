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

//��ʼ����������
struct ListNode* ListInit();

//��ӡ��������
void ListPrintf(struct ListNode* phead);

//���ٺ�������
void ListDestory(struct ListNode* phead);

//β�庯������
void ListPushBack(struct ListNode* phead, int x);

//βɾ��������
void ListPopBack(struct ListNode* phead);

//ͷ�庯������
void ListPushFront(struct ListNode* phead, int x);

//ͷɾ��������
void ListPopFront(struct ListNode* phead);

//���Һ�������
struct ListNode* ListFind(struct ListNode* phead, int x);

//���뺯������
void ListInsert(struct ListNode* pos, int x);

//ɾ����������
void ListErase(struct ListNode* pos);
