#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////交换排序
//冒泡排序
//时间复杂度O(n^2)
//外层比较次数 n
//内层比较次数
//n-1
//n-2
//n-3
//最好情况O(n)
//跟直接插入排序相比？ 直接插入排序更优! 对有序、接近有序、局部有序,直接插入排序适应性更强
void BubbleSort(int* a, int n)
{
    //int i = 0, j = 0, flag = 1;
    //for (i = 0; i < n; i++)
    //{
    //    for (j = 1; j < n - i; j++)
    //    {
    //        if (a[j - 1] > a[j])
    //        {
    //            Swap(&a[j - 1], &a[j]);
    //            flag = 0;
    //        }
    //    }
    //    if (flag == 1)
    //    {
    //        break;
    //    }
    //    flag = 1;
    //}

    //等价于
    int end = n, i = 0, flag = 1;
    while (end > 0)
    {
        for (i = 1; i < end; i++)
        {
            if (a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
        flag = 1;
        --end;
    }
}


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

//单趟排序
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

//左右指针法
int PartSortPlus(int* a, int left, int right)
{
    int index = GetMidIndex(a, left, right);
    Swap(&a[left], &a[right]);

    int begin = left, end = right;
    int keyi = begin;

    while (begin < end)
    {
        //找小
        while (begin < end && a[end] >= a[keyi])
        {
            --end;
        }

        //找大
        while (begin < end && a[begin] <= a[keyi])
        {
            ++begin;
        }

        //交换
        Swap(&a[begin], &a[end]);
    }

    Swap(&a[begin], &a[keyi]);

    return begin;
}

//前后指针法
int PartSortPro(int* a, int left, int right)
{
    int index = GetMidIndex(a, left, right);
    Swap(&a[left], &a[right]);

    int keyi = left;
    int prev = left, cur = left + 1;

    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur) //位置相同不用交换(prev == cur)
        {
            //++prev;
            Swap(&a[cur], &a[prev]);
        }

        cur++;
    }

    Swap(&a[keyi], &a[prev]);

    return prev;
}

//快速排序
//快排属于不稳定的排序方法
//单趟排序的时间复杂度为O(n)   取logn次的key值
//时间复杂度O(nlogn)
//最坏的情况是? 有序的情况!  O(n^2)
void QuickSort(int* a, int left, int right)
{
    if (left >= right) //left > right区间不存在  left == right 区间只有一个值
        return;

    //挖坑法
    //int keyIndex = PartSort(a,  left, right);

    //左右指针法
    int keyIndex = PartSortPro(a, left, right);

    //[left,right]
    //[left, pivot-1] [pivot+1, right] 两个子区间
    //左子区间和右子区间有序,我们就有序了,如何让它们有序呢? 分治递归!

    //小区间优化,最后几次递归的次数较多,区间的数据较少,直接使用插入排序的效果更好
    if ((keyIndex - 1) - left > 10)
    {
        QuickSort(a, left, right);
    }
    else
    {
        InsertSort(a + left, (keyIndex - 1) - left + 1);
    }

    if (right - (keyIndex + 1) > 10)
    {
        QuickSort(a, keyIndex + 1, right);
    }
    else
    {
        InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
    }

}


//int main(void)
//{
//    int data[] = { 1,3,5,7,9,2,4,6,8,10,-1 };
//    QuickSort(data, 0, 10);
//    Print(data, sizeof(data) / sizeof(data[0]));
//    return 0;
//}