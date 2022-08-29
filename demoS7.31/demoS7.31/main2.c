#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
struct ListNode
{
    int data;
    struct ListNode* next;
};

//�ж������Ƿ��л�(����ָ��)
int hasCycle(struct ListNode* phead)
{
    struct ListNode* slow = NULL, * fast = NULL;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1; //�л�
        }
    }
    return 0;
}

// int main(void) 
// {
//     struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     n1->data = 1,n2->data = 2,n3->data = 3,n4->data = 4,n5->data = 5;
//     n1->next = n2,n2->next = n3,n3->next = n4,n4->next = n5,n5->next = NULL;
//     PrintList(n1);
//     int ret = hasCycle(n1);
//     if(ret == 1)
//     {
//         printf("true\n");
//     }
//     else 
//     {
//         printf("false\n");
//     }
//     return 0;
// }

/*
  ��������
  1��Ϊʲôslow��fastһ�����ڻ�������?�᲻���ڻ�����,��Զ������,��֤��һ�£� ����:����һ��������!
      ����֤��:
      ��һ��: slow��fast,fastһ�����Ƚ���,��ʱslow�����뻷ǰ�����һ��
      �ڶ���: ����slow����,fast�Ѿ��ڻ����߹���һ��,���˶��ٸ����Ĵ�С�й�ϵ

      ����slow������ʱ��,slow��fast֮��ľ���ΪN,fast��ʼ׷slow
      slowÿ����ǰһ��, fast��ǰ׷2��, ÿ׷һ��, �ж�һ���Ƿ�����
      ÿ׷һ��, fast��slow�ľ���任:
                                N
                                N-1
                                N-2
                                N-3
                                ...
                                1
                                0
      ÿ׷һ��,�������һ��,����֮��ľ���������0��ʱ��,���������ĵ�

  2��Ϊʲôslow��һ��,fast��������? �ܲ���fastһ����n��,��֤��һ��!  ����:fastһ��n��? n>2��һ������
     ����: slowһ����һ��, fastһ��������
           slow�����Ժ�, fast��slow֮��ľ���N, fast��ʼ׷slow

           ����֮��ľ���仯����:
                      N��ż��          N������
                      N                N
                      N-2              N-2
                      N-4              N-4
                      N-6              N-6
                      ...              ...
                      2                1
                      0                -1            ���N������,������-1��ζ��ʲô? ��ζ������֮��ľ���ΪC-1(CΪ���ĳ���)
                      ����׷��         ��һ��׷����    ���C-1������,��ô����Զ׷������
                                                     ���C-1��ż��,��ô����׷����


    3������slowһ����һ��,fastһ����n���Ƶ����̺�ǰ������
       �ٿ�һ��slowһ����1��,fastһ����4��
       ����slow����,fast��ʼ׷ʱ,slow��fast֮��ľ�����N
       ׷�ľ���仯:
           N��3�ı���          N����3�ı���
           N               N          N
           N-3             N-3        N-3
           N-6             N-6        N-6
           N-9             N-9        N-9
           ...             ...        ...
           3               2          1
           0               -1         -2            ����C�ǻ��ĳ���
        ����׷��             ��һ��׷����             -1��ζ�ž�����C-1
                                                    -2��ζ�ž�����C-2
                                                    ���C-1��C-2��3�ı����Ϳ���׷��
                                                    �����׷����
*/

//�󻷵���ڵ�
/*
  ׷�������Ĺ�����
  ��ָ���ߵľ���: L + X
  ��ָ���ߵľ���: L + N*C + X (2 > N >=1)
                 N����������֮ǰ,fast�ڻ����ߵ�Ȧ��

  ��ָ���ߵ�·������ָ���2��
  2(L + X) = L + N * C + X
  L + X = N * C
  L = N*C - X
  L = (N-1)*C + C-X

*/

//�������л�,�ҳ�������ڽڵ�
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //����
            struct ListNode* meet = slow;
            //��ʽ֤��
            while (head != meet)
            {
                meet = meet->next;
                head = head->next;
            }
            return meet;
        }
    }
    return NULL;

}

//�ڶ��汾(ת��Ϊ�����ཻ������)
struct ListNode* detectCyclePlus(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //�����㸳ֵ���µ�ͷ�ڵ�,ת��Ϊ�����ཻ����
            struct ListNode* newHead = slow->next;
            struct ListNode* cur1 = head, * cur2 = newHead;
            int len1 = 0, len2 = 0, k = 0;
            //������������ĳ���,������Ȳ�ֵ
            while (cur1 != slow)
            {
                cur1 = cur1->next;
                len1++;
            }
            while (cur2 != slow)
            {
                cur2 = cur2->next;
                len2++;
            }
            //�ϳ����������߳��Ȳ�ֵ
            if (len1 > len2)
            {
                k = len1 - len2;
                while (k)
                {
                    head = head->next;
                    k--;
                }
            }
            else if (len1 < len2)
            {
                k = len2 - len1;
                while (k)
                {
                    newHead = newHead->next;
                    k--;
                }
            }
            //��������ͬʱ�ƶ�,�ҳ��ཻ�Ľڵ�
            while (head && newHead)
            {
                if (head == newHead)
                {
                    return head;
                }
                else
                {
                    head = head->next;
                    newHead = newHead->next;
                }
            }
        }
    }
    return NULL;
}


// int main(void) 
// {
//     struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     n1->data = 1,n2->data = 2,n3->data = 3,n4->data = 4,n5->data = 5;
//     n1->next = n2,n2->next = n3,n3->next = n4,n4->next = n5,n5->next = n3;
//     struct ListNode* meet = detectCycle(n1);
//     if(meet != NULL)
//     {
//         printf("%d\n", meet->data);
//     }
//     else 
//     {
//         printf("NULL\n");
//     }
//     return 0;
// }