#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

struct ListNode
{
	int  data;
	struct ListNode* next;
};

//分隔链表
struct ListNode* partition(struct ListNode* phead, int x)
{
	assert(phead);
	struct ListNode* lessHead = NULL, * lessTail = NULL, * greaterHead = NULL, * greaterTail = NULL;
	//开辟哨兵位头节点,方便尾插
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterTail->next = NULL;

	struct ListNode* cur = phead;
	while (cur)
	{
		if (cur->data < x)
		{
			lessTail->next = cur;
			lessTail = cur;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = cur;
		}
		cur = cur->next;
	}

	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;//最后一个元素的next置空,放置形成环

	struct ListNode* newHead = lessHead->next;
	free(lessHead);
	free(greaterHead);

	return newHead;
}

//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->data = 4; n2->data = 3; n3->data = 2; n4->data = 5; n5->data = 1;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	ListPrint(n1);
//	struct ListNode* head = partition(n1,3);
//	ListPrint(head);
//	return 0;
//}

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

//判断是否是回文结构
int chkPalindrome(struct ListNode* head)
{
	//找到中间节点
	struct ListNode* mid = middleNode(head);
	//逆转链表
	struct ListNode* newHead = reverseList(mid);
	struct ListNode* curA = head;
	struct ListNode* curB = newHead;
	while (curA && curB)
	{
		if (curA->data != curB->data)
		{
			return 0;
		}
		else
		{
			curA = curA->next;
			curB = curB->next;
		}
	}
	return 1;
}

//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->data = 1; n2->data = 2; n3->data = 4; n4->data = 3; n5->data = 2; n6->data = 1;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6; n6->next = NULL;
//	ListPrint(n1);
//	int ret = chkPalindrome(n1);
//	if (ret == 1)
//	{
//		printf("true\n");
//	}
//	else
//	{
//		printf("false\n");
//	}
//	return 0;
//}


//相交链表,找出相交的节点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* tailA = headA, * tailB = headB;
	int lenA = 1, lenB = 1;

	//先找尾节点,计算链表的长度
	while (tailA->next)
	{
		lenA++;
		tailA = tailA->next;
	}
	while (tailB->next)
	{
		lenB++;
		tailB = tailB->next;
	}
	//判断链表是否相交
	if (tailA != tailB)
	{
		return NULL;
	}
	//计算差距步
	int gap = abs(lenA - lenB);

	//长的链表先走差距步,再同时走,找交点
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	if (lenA < lenB)
	{
		shortList = headB;
		longList = headB;
	}
	//先移动较长链表
	while (gap--)
	{
		longList = longList->next;
	}
	//移动两个链表,寻找交点
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}
