#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

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

//////////////////插入排序

//直接插入排序
//时间复杂度O(n^2)
//时间复杂度看最坏情况？逆序 等差数列 1+2+3+...+n-1  O(n^2)
//什么情况最好? 顺序有序 O(n)
//空间复杂度为O(1)
//一种稳定的排序算法
void InsertSort(int* a, int n)
{
    //[0,end]有序  end + 1位置的值插入进去,让[0, end + 1]有序
    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}


//希尔排序(缩小增量排序)
//直接在插入排序的基础上优化
//1、先进行预排序,让数组接近有序
//2、直接插入排序(gap == 1)
//时间复杂度O(nlogn)或者O(nlog3n)
//平均的时间复杂度O(n^1.3)
//不稳定排序算法
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        //gap = gap / 3 + 1; //log3n 以3为底数
        gap = gap / 2;  //log2n 以2为底数
        //gap最后一次必须是1
        //gap > 1时都是预排序 目的是，接近有序
        //gap == 1时就是直接插入排序
        int i = 0;

        //gap很大时,下面预排序时间复杂度O(n)
        //gap很小时,数组接近有序,这时复杂度接近O(n)

        //把间隔为gap的多组数据同时排序
        for (i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > tmp)
                {
                    a[end + gap] = a[end];
                    end = end - gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

//int main(void) {
//    int data[] = { 1,3,5,7,9,2,4,6,8,10 };
//    InsertSort(data, sizeof(data) / sizeof(data[0]));
//    Print(data, sizeof(data) / sizeof(data[0]));
//    printf("%d\n", clock()); //clock()库函数可以获取此时系统时间的毫秒数
//    return 0;
//}


