#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

struct ListNode
{
    int data;
    struct ListNode* next;
    struct ListNode* random;
};

//��ӡ����
void PrintList(const struct ListNode* phead)
{
    const struct ListNode* cur = phead;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//��ӡ���������ָ�����Ϣ
void PrintListRandow(const struct ListNode* phead)
{
    const struct ListNode* cur = phead;
    while (cur)
    {
        printf("%d ", (cur->random)->data);
        cur = cur->next;
    }
    printf("\n");
}

//��ȿ�������
struct ListNode* copyRandomList(struct ListNode* head)
{
    //1�������ڵ�copy������뵽ԭ�ڵ�ĺ���
    struct ListNode* cur = head;
    while (cur)
    {
        //���ɽڵ�,¼������
        struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
        copy->data = cur->data;
        //�����½ڵ�
        copy->next = cur->next;
        cur->next = copy;
        //�����ڵ�
        cur = copy->next;
    }

    //2������Դ�ڵ�,����copy�ڵ��random
    cur = head;
    while (cur)
    {
        struct ListNode* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }

    //3���������ؽڵ��ȡ����,���ӳ��µ�����
    struct ListNode* copyHead = NULL, * copyTail = NULL;
    cur = head;
    while (cur)
    {
        struct ListNode* copy = cur->next;
        struct ListNode* next = copy->next;

        if (copyTail == NULL)
        {
            copyHead = copyTail = copy;
        }
        else
        {
            copyTail->next = copy;
            copyTail = copy;
        }
        cur->next = next;
        cur = next;
    }

    return copyHead;
}

int main(void)
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->data = 1, n2->data = 2, n3->data = 3, n4->data = 4, n5->data = 5;
    n1->next = n2, n2->next = n3, n3->next = n4, n4->next = n5, n5->next = NULL;

    n1->random = n3, n2->random = n4, n3->random = n5, n4->random = n2, n5->random = n1;
    PrintList(n1);

    struct ListNode* head = copyRandomList(n1);
    PrintList(head);
    PrintListRandow(head);
    return 0;
}