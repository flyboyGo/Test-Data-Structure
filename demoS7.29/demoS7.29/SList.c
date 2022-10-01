#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//打印函数声明实现
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

//新节点生成函数
static SLNode* CreateListNode(SLDataType  x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	assert(newnode != NULL);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插函数实现
void SListPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	//生成新的节点,并装填数据
	SLNode* newnode = CreateListNode(x);
	//插入节点
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//新节点装填数据
		newnode->data = x;
		newnode->next = NULL;
		//插入尾节点
		tail->next = newnode;
	}
}

//头插函数实现
void SListPushFront(SLNode** pphead, SLDataType x)
{
	//生成新的节点,并装填数据
	SLNode* newnode = CreateListNode(x);
	//插入新节点
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删函数声明
void SListPopBack(SLNode** pphead)
{
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		//释放已删除的节点空间
		free((*pphead)->next);
		*pphead = NULL;
	}
	else
	{
		//方式一
		// SLNode* tail = *pphead, *prev = *pphead;
		// while(tail->next != NULL)
		// {
		//       prev = tail;
		//       tail = tail->next;
		// }
		// prev->next = NULL;
		// //释放已删除的节点空间
		// free(tail);
		// tail = NULL;

		//方式二
		SLNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}

//头删函数声明
void SListPopFront(SLNode** pphead)
{
	assert(*pphead);
	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

//查找函数实现
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

//插入函数实现(默认在pos位置之前插入一个节点)
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
//改进版
void SListInsertPlus(SLNode** pphead, SLNode* pos, SLDataType x)
{
	SLNode* newnode = CreateListNode(x);
	if (*pphead != pos)
	{
		//找到pos前一个位置
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

//插入函数实现(默认在pos位置之后插入函数)
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

//删除函数实现
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
//改进版
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
//改进版(删除pos后一个)
void SListEraseAfter(SLNode** pphead, SLNode* pos)
{
	assert(pos->next);
	assert(pos);
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//销毁函数实现
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
