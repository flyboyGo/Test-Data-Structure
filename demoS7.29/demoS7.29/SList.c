#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//��ӡ��������ʵ��
void SListPrint(const SLNode* phead)
{
	const SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//�½ڵ����ɺ���
static SLNode* CreateListNode(SLDataType  x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode != NULL);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//β�庯��ʵ��
void SListPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	//�����µĽڵ�,��װ������
	SLNode* newnode = CreateListNode(x);
	//����ڵ�
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

//ͷ�庯��ʵ��
void SListPushFront(SLNode** pphead, SLDataType x)
{
	//�����µĽڵ�,��װ������
	SLNode* newnode = CreateListNode(x);
	//�����½ڵ�
	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ��������
void SListPopBack(SLNode** pphead)
{
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		//�ͷ���ɾ���Ľڵ�ռ�
		free((*pphead)->next);
		*pphead = NULL;
	}
	else
	{
		//��ʽһ
		// SLNode* tail = *pphead, *prev = *pphead;
		// while(tail->next != NULL)
		// {
		//       prev = tail;
		//       tail = tail->next;
		// }
		// prev->next = NULL;
		// //�ͷ���ɾ���Ľڵ�ռ�
		// free(tail);
		// tail = NULL;

		//��ʽ��
		SLNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}

//ͷɾ��������
void SListPopFront(SLNode** pphead)
{
	assert(*pphead);
	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

//���Һ���ʵ��
SLNode* SListFind(SLNode* pphead, SLDataType x)
{
	assert(pphead);
	SLNode* cur = pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//���뺯��ʵ��(Ĭ����posλ��֮ǰ����һ���ڵ�)
void SListInsert(SLNode** pphead, int pos, SLDataType x)
{
	if (*pphead == NULL)
	{
		SLNode* newnode = CreateListNode(x);
		newnode->next = NULL;
		*pphead = newnode;
	}
	else
	{

		SLNode* tmp = *pphead, * before = *pphead;
		while ((pos - 1) && (tmp != NULL))
		{
			before = tmp;
			tmp = tmp->next;
			pos--;
		}
		if ((pos - 1) == 0)
		{
			SLNode* newnode = CreateListNode(x);
			newnode->next = tmp;
			before->next = newnode;
		}
		else
		{
			assert(pos);
		}
	}
}
//�Ľ���
void SListInsertPlus(SLNode** pphead, SLNode* pos, SLDataType x)
{
	SLNode* newnode = CreateListNode(x);
	if (*pphead != pos)
	{
		//�ҵ�posǰһ��λ��
		SLNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}

}

//���뺯��ʵ��(Ĭ����posλ��֮����뺯��)
void SListInsertAfter(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(*pphead);
	SLNode* newnode = CreateListNode(x);
	SLNode* tmp = *pphead;

	while (tmp)
	{
		if (tmp == pos)
		{
			newnode->next = tmp->next;
			tmp->next = newnode;
		}
		tmp = tmp->next;
	}
}

//ɾ������ʵ��
void SListErase(SLNode** pphead, int pos)
{
	assert(*pphead);
	assert(pos);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* tmp = *pphead, * before = *pphead;
		while ((pos - 1) && (tmp != NULL))
		{
			before = tmp;
			tmp = tmp->next;
			pos--;
		}

		if ((pos - 1) == 0 && (tmp == before))
		{
			*pphead = (*pphead)->next;
		}
		else if (pos - 1 == 0)
		{
			before->next = tmp->next;
			free(tmp);
			tmp = NULL;
		}
		else
		{
			assert(pos);
		}

	}
}
//�Ľ���
void SListErasePlus(SLNode** pphead, SLNode* pos)
{
	assert(*pphead);
	assert(pos);
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//�Ľ���(ɾ��pos��һ��)
void SListEraseAfter(SLNode** pphead, SLNode* pos)
{
	assert(pos->next);
	assert(pos);
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//���ٺ���ʵ��
void SListDestory(SLNode** pphead)
{
	assert(pphead);
	SLNode* next = *pphead;
	while (*pphead)
	{
		next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
	*pphead = NULL;
}
