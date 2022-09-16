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

void ListPrint(struct ListNode* head)
{
	assert(head);
	struct ListNode* cur = head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//翻转链表
struct ListNode* reverseList(struct ListNode* head)
{
	assert(head);
		struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
		while (n2)
		{
			//翻转
			n2->next = n1;
			//迭代
			n1 = n2;
			n2 = n3;
			if (n3)
			{
				n3 = n3->next;
			}  
		}
		return n1 ;
};

//改进版
struct ListNode* my_reverseList(struct ListNode* head)
{
	assert(head);
	struct ListNode* cur = head, *tmp = NULL, *newHead = NULL;
	while (cur)
	{
		tmp = cur->next;
		//头插
		cur->next = newHead;
		newHead = cur;
		//迭代
		cur = tmp;
	}
	return newHead;
};

//int main()
//{
//	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head->data = 1; n2->data = 2; n3->data = 3; n4->data = 4; n5->data = 5;
//	head->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	ListPrint(head);
//	head = my_reverseList(head);
//	ListPrint(head);
//	return 0;
//}