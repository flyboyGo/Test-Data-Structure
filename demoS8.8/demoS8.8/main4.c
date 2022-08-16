#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////////////归并排序

//子函数
void _MergeSort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    //假设[left, mid] [mid+1, right]有序,我们可以归并了
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int index = left;
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

    while (begin1 <= end1)
    {
        tmp[index++] = a[begin1++];
    }
    while (begin2 <= end2)
    {
        tmp[index++] = a[begin2++];
    }

    //拷贝数据
    int i = 0;
    for (i = left; i <= right; i++)
    {
        a[i] = tmp[i];
    }
}

void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
}


//int main(void)
//{
//    int data[] = { 1,3,5,7,9,2,4,6,8,10,-1 };
//    MergeSort(data, sizeof(data) / sizeof(int));
//    Print(data, sizeof(data) / sizeof(data[0]));
//    return 0;
//}