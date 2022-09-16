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

//�ָ�����
struct ListNode* partition(struct ListNode* phead, int x)
{
	assert(phead);
	struct ListNode* lessHead = NULL, * lessTail = NULL, * greaterHead = NULL, * greaterTail = NULL;
	//�����ڱ�λͷ�ڵ�,����β��
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
	greaterTail->next = NULL;//���һ��Ԫ�ص�next�ÿ�,�����γɻ�

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

//�ҳ�������м�ڵ�
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

//�ж��Ƿ��ǻ��Ľṹ
int chkPalindrome(struct ListNode* head)
{
	//�ҵ��м�ڵ�
	struct ListNode* mid = middleNode(head);
	//��ת����
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


//�ཻ����,�ҳ��ཻ�Ľڵ�
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* tailA = headA, * tailB = headB;
	int lenA = 1, lenB = 1;

	//����β�ڵ�,��������ĳ���
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
	//�ж������Ƿ��ཻ
	if (tailA != tailB)
	{
		return NULL;
	}
	//�����ಽ
	int gap = abs(lenA - lenB);

	//�����������߲�ಽ,��ͬʱ��,�ҽ���
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	if (lenA < lenB)
	{
		shortList = headB;
		longList = headB;
	}
	//���ƶ��ϳ�����
	while (gap--)
	{
		longList = longList->next;
	}
	//�ƶ���������,Ѱ�ҽ���
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}

	return longList;
}
