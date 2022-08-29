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

//判断链表是否有环(快慢指针)
int hasCycle(struct ListNode* phead)
{
    struct ListNode* slow = NULL, * fast = NULL;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1; //有环
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
  延伸问题
  1、为什么slow和fast一定会在环中相遇?会不会在环里错过,永远遇不上,请证明一下！ 结论:它们一定会相遇!
      分析证明:
      第一步: slow和fast,fast一定是先进环,此时slow走了入环前距离的一半
      第二步: 随着slow进环,fast已经在环中走过了一段,走了多少跟环的大小有关系

      假设slow进环的时候,slow与fast之间的距离为N,fast开始追slow
      slow每次往前一步, fast往前追2步, 每追一次, 判断一下是否相遇
      每追一次, fast和slow的距离变换:
                                N
                                N-1
                                N-2
                                N-3
                                ...
                                1
                                0
      每追一次,距离减少一次,它们之间的距离最后减到0的时候,就是相遇的点

  2、为什么slow走一步,fast走两步呢? 能不能fast一次走n步,请证明一下!  结论:fast一次n步? n>2不一会相遇
     假设: slow一次走一步, fast一次走三步
           slow进环以后, fast跟slow之间的距离N, fast开始追slow

           它们之间的距离变化如下:
                      N是偶数          N是奇数
                      N                N
                      N-2              N-2
                      N-4              N-4
                      N-6              N-6
                      ...              ...
                      2                1
                      0                -1            如果N是奇数,距离变成-1意味着什么? 意味着它们之间的距离为C-1(C为环的长度)
                      可以追上         这一次追不上    如果C-1是奇数,那么就永远追不上了
                                                     如果C-1是偶数,那么可以追上了


    3、假设slow一次走一步,fast一次走n步推到过程和前面类似
       再看一下slow一次走1步,fast一次走4步
       假设slow进环,fast开始追时,slow与fast之间的距离是N
       追的距离变化:
           N是3的倍数          N不是3的倍数
           N               N          N
           N-3             N-3        N-3
           N-6             N-6        N-6
           N-9             N-9        N-9
           ...             ...        ...
           3               2          1
           0               -1         -2            假设C是环的长度
        可以追上             这一次追不上             -1意味着距离是C-1
                                                    -2意味着距离是C-2
                                                    如果C-1和C-2是3的倍数就可以追上
                                                    否则就追不上
*/

//求环的入口点
/*
  追上相遇的过程中
  慢指针走的距离: L + X
  快指针走的距离: L + N*C + X (2 > N >=1)
                 N是它们相遇之前,fast在环里走的圈数

  快指针走的路程是慢指针的2倍
  2(L + X) = L + N * C + X
  L + X = N * C
  L = N*C - X
  L = (N-1)*C + C-X

*/

//链表中有环,找出环的入口节点
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //相遇
            struct ListNode* meet = slow;
            //公式证明
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

//第二版本(转换为链表相交的问题)
struct ListNode* detectCyclePlus(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //相遇点赋值给新的头节点,转化为链表相交问题
            struct ListNode* newHead = slow->next;
            struct ListNode* cur1 = head, * cur2 = newHead;
            int len1 = 0, len2 = 0, k = 0;
            //计算两个链表的长度,算出长度差值
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
            //较长的链表先走长度差值
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
            //两个链表同时移动,找出相交的节点
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