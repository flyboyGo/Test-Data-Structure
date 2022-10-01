#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef struct ListNode
{
	int  data;
	struct SListNode* next;
}SLNode;
//ȥ�غ���(����)
 SLNode* removeElements(SLNode* head, int val)
{
    SLNode* prev = head, * cur = head;
	while (cur)
	{
		if (cur->data == val)
		{
			//ͷɾ
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			//����λ��ɾ��
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else //����
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

//int main()
//{
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	n1->data = 2; n2->data = 3; n3->data = 2; n4->data = 4; n5->data = 2;
//	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = NULL;
//	SListPrint(n1);
//	SLNode* head = removeElements(n1, 2);
//	SListPrint(head);
//	return 0;
//}