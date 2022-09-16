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

//判断链表是否带环
int hasCycle(struct ListNode* head)
{
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;

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
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6; n6->next = n1;
//	int ret = hasCycle(n1);
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