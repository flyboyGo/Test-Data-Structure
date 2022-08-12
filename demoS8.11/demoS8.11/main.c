#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

//递归的缺陷:在某些极端情况下,由于递归的深度太深,栈中堆积了太多的函数的栈帧无法及时释放,
//会导致栈空间不够用,可能会溢出。
//非递归
//递归改非递归: 1、直接改循环 2、借助数据结构模拟递归过程(复杂一点)

//三数取中
int GetMidIndex(int* a, int left, int right)
{
    int mid = (left + right) >> 1;
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
        {
            return mid;
        }
        else if (a[left] > a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else  //a[left] > a[mid]
    {
        if (a[mid] > a[right])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

//交换数据
void Swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//打印函数
void Print(int* a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//挖坑法
int PartSort(int* a, int left, int right)
{
    //三数取中,解决了快排排列有序数据时的问题
    int index = GetMidIndex(a, left, right); //取中间值,头尾中三个值中的中间值
    Swap(&a[left], &a[index]);//交换中间值与头的位置,保证函数主体逻辑不变

    int begin = left, end = right;
    int pivot = begin;
    int key = a[begin];

    while (begin < end)//单趟排序的时间复杂度为O(n)
    {
        //右边找小、放到左边
        while (a[end] >= key && begin < end)
        {
            --end;
        }
        //小的放到左边的坑中,自己形成新的坑位
        a[pivot] = a[end];
        pivot = end;

        while (a[begin] <= key && begin < end)
        {
            ++begin;
        }
        //大的放到右边的坑中,自己形成新的坑位
        a[pivot] = a[begin];
        pivot = begin;
    }
    pivot = begin;
    a[pivot] = key;

    return pivot;
}

//快排(非递归)
//用栈模拟递归(队列也可以)
void QuickSortNonR(int* a, int n)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, n - 1);
    StackPush(&st, 0);

    while (!StackEmpty(&st))
    {
        int left = StackTop(&st);//取栈顶元素,先得到左下标
        StackPop(&st);

        int right = StackTop(&st);//取栈顶元素,后得到右下标
        StackPop(&st);

        int keyIndex = PartSort(a, left, right);

        //[left, keyIndex - 1] [keyIndex + 1, right] 分割后的两个区间

        //先入右区间
        if (keyIndex + 1 < right)
        {
            StackPush(&st, right); //先入右下标
            StackPush(&st, keyIndex + 1);//后入左下标
        }

        //后入左区间
        if (left < keyIndex - 1)
        {
            StackPush(&st, keyIndex - 1); 
            StackPush(&st, left);
        }
    }

    StackDestory(&st);
}


//归并排序(非递归)(此方法类似于队列效果)
//时间复杂度O(nlogn)
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);

    int gap = 1;//每组数据个数
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap)
        {
            //[i, i+gap-1] [i+gap, i+2*gap-1]

            int begin1 = i, end1 = i + gap - 1; 
            int begin2 = i + gap, end2 = i + 2 * gap - 1;

            //归并过程中右区间可能就不存在
            //这种情况,只有在每次内层归并循环的最后一次可能出现
            //右区间不存在,左区间有序,无需归并,直接结束
            if (begin2 >= n)
            {
                break;
            }

            //归并过程中右区间存在,但不满个数
            //这种情况,只有在每次内层归并循环的最后一次可能出现
            //修正个数
            if (end2 >= n)
            {
                end2 = n - 1;
            }

            //归并过程中左区间存在,但不满个数,
            //这种情况,只有在每次内层归并循环的最后一次可能出现
            //左区间存在,但不满个数,但有序,此时右区间一定不存在,无需处理(无需归并、拷贝)

            int index = i;
            //开始归并
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] < a[begin2])
                {
                    tmp[index++] = a[begin1++];
                }
                else
                {
                    tmp[index++] = a[begin2++];
                }
            }

            //归并剩余数据
            while (begin1 <= end1)
            {
                tmp[index++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                tmp[index++] = a[begin2++];
            }

            //拷贝数据
            for (int j = i; j <= end2 ; j++)
            {
                a[j] = tmp[j];
            }
        }

        gap = gap * 2;
    }

    free(tmp);
}

//int main(void)
//{
//    int data[] = { 1,3,5,7,9,2,4,6,8,10};
//    MergeSortNonR(data, sizeof(data) / sizeof(data[0]));
//    Print(data, sizeof(data) / sizeof(data[0]));
//    return 0;
//}
