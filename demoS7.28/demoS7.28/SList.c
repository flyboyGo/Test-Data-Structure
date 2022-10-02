#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//��ӡ��������ʵ��
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

//β�庯��ʵ��
void SListPushBack(SLNode** pphead, SLDataType x)
{
	//�����µĽڵ�
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode != NULL);
	//�½ڵ�װ������
	newnode->data = x;
	newnode->next = NULL;
	
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β�ڵ�
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//�½ڵ�װ������
		newnode->data = x;
		newnode->next = NULL;
		//����β�ڵ�
		tail->next = newnode;
	}
}