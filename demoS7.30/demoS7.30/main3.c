#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

struct ListNode
{
	int data;
	struct ListNode* next;
};

//找出链表的中间节点
static struct ListNode* middleNode(struct ListNode* head)
{
	assert(head);
	struct ListNode* slow, * fast;
	slow = fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//找出链表的倒数第k个节点
struct ListNode* FindKthToTail(struct ListNode* head, int k)
{
	assert(head);
	struct ListNode* slow, * fast;
	slow = fast = head;
	while(k>0)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
		k--;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//int main()
//{
//	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head->data = 1; n2->data = 2; n3->data = 3; n4->data = 4; n5->data = 5;
//	head->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	//ListPrint(head);
//	//head = middleNode(head);
//	//printf("%d\n", head->data);
//	//head = FindKthToTail(head, 4);
//	//printf("%d\n", head->data);
//	return 0;
//}


//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	//如果其中一个链表为空
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode *head = NULL, *tail = NULL;

	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			if (head == NULL)
			{
				head = tail = l1;
			}
			else
			{
				tail->next = l1;
				tail = l1;
				
			}
			l1 = l1->next;
		}
		else
		{
			if (head == NULL)
			{
				head = tail = l2;
			}
			else
			{
				tail->next = l2;
				tail = l2;
			}
			
			l2 = l2->next;
		}
	}

	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}
	return head;
}
//改进版(带头结点,哨兵位的头节点)
struct ListNode* mergeTwoListsPlus(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = NULL, * tail = NULL;
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
	}

	if (l1)
	{
		tail->next = l1;
	}
	else if(l2)
	{
		tail->next = l2;
	}

	struct ListNode* list = head->next;
	free(head);
	return list;
}

//int main()
//{
//	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head->data = 1; n2->data = 3; n3->data = 5;
//	head->next = n2; n2->next = n3; n3->next = NULL;
//	ListPrint(head);
//
//	struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head2->data = 2; n4->data = 4; n5->data = 6;
//	head2->next = n4; n4->next = n5; n5->next = NULL;
//	ListPrint(head2);
//
//	head = mergeTwoListsPlus(head, head2);
//	ListPrint(head);
//	return 0;
//}