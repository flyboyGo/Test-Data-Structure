#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////////选择排序

//交换数据
void Swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//直接选择排序
//时间复杂度O(n^2)
//外层比较次数  n/2
//内层比较次数
//n      
//n-2    
//n-4    
//很差,因为最好的情况(有序情况)也是O(n^2)
void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1, i = 0;
    while (begin < end)
    {
        int mini = begin, maxi = begin;
        for (i = begin; i <= end; i++)
        {
            if (a[i] < mini)
            {
                mini = i;
            }
            if (a[i] > maxi)
            {
                maxi = i;
            }
        }

        Swap(&a[begin], &a[mini]);
        if (begin == maxi)
        {
            maxi = mini;
        }
        Swap(&a[end], &a[maxi]);
        ++begin;
        --end;
    }
}



//堆排序
//整体时间复杂度O(nlogn)
//不稳定排序算法

//向下调整算法
//调小堆
void AdjustDownMin(int* a, int n, int root)
{
    //最多调整高度次:(h-1)
    int parent = root;
    int child = parent * 2 + 1;//默认左孩子
    while (child < n)
    {
        //1、选出左右孩子中小的那一个
        if (child + 1 < n && a[child + 1] < a[child])
        {
            child += 1;
        }
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else if (a[child] > a[parent])
        {
            break;
        }
    }
}

//调大堆
void AdjustDownMax(int* a, int n, int root)
{
    //最多调整高度次:(h-1) 2^h - 1 - x = n ==> log2(1+x+n) = h ==> h = logn
    //时间复杂度O(logn)
    int parent = root;
    int child = parent * 2 + 1;//默认左孩子
    while (child < n)
    {
        //1、选出左右孩子中大的那一个
        if (child + 1 < n && a[child + 1] > a[child])
        {
            child += 1;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

//建堆(升序)
void HeapSort(int* a, int n)
{
    //建大堆(从最后一个叶子节点的父节点开始调)
    //建堆的时间复杂度为:O(n)
    int i = 0;
    for (i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDownMax(a, n, i);
    }

    //排升序,建大堆还是小堆? 建大堆!
    int end = n - 1;
    while (end > 0) //外层复杂度O(n)
    {
        Swap(&a[0], &a[end]);
        AdjustDownMax(a, end, 0);
        --end;
    }
}

//测试版(降序)
void HeapSortPlus(int* a, int n)
{
    //建小堆(从最后一个叶子节点的父节点开始调)
    int i = 0;
    for (i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDownMin(a, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDownMin(a, end, 0);
        --end;
    }
}

//int main(void)
//{
//    int data[] = { 1,3,5,7,9,2,4,6,8,10 };
//    SelectSort(data, 10);
//    Print(data, sizeof(data) / sizeof(data[0]));
//    return 0;
//}