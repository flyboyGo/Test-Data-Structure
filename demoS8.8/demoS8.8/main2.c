#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////////ѡ������

//��������
void Swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//ֱ��ѡ������
//ʱ�临�Ӷ�O(n^2)
//���Ƚϴ���  n/2
//�ڲ�Ƚϴ���
//n      
//n-2    
//n-4    
//�ܲ�,��Ϊ��õ����(�������)Ҳ��O(n^2)
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



//������
//����ʱ�临�Ӷ�O(nlogn)
//���ȶ������㷨

//���µ����㷨
//��С��
void AdjustDownMin(int* a, int n, int root)
{
    //�������߶ȴ�:(h-1)
    int parent = root;
    int child = parent * 2 + 1;//Ĭ������
    while (child < n)
    {
        //1��ѡ�����Һ�����С����һ��
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

//�����
void AdjustDownMax(int* a, int n, int root)
{
    //�������߶ȴ�:(h-1) 2^h - 1 - x = n ==> log2(1+x+n) = h ==> h = logn
    //ʱ�临�Ӷ�O(logn)
    int parent = root;
    int child = parent * 2 + 1;//Ĭ������
    while (child < n)
    {
        //1��ѡ�����Һ����д����һ��
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

//����(����)
void HeapSort(int* a, int n)
{
    //�����(�����һ��Ҷ�ӽڵ�ĸ��ڵ㿪ʼ��)
    //���ѵ�ʱ�临�Ӷ�Ϊ:O(n)
    int i = 0;
    for (i = (n - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDownMax(a, n, i);
    }

    //������,����ѻ���С��? �����!
    int end = n - 1;
    while (end > 0) //��㸴�Ӷ�O(n)
    {
        Swap(&a[0], &a[end]);
        AdjustDownMax(a, end, 0);
        --end;
    }
}

//���԰�(����)
void HeapSortPlus(int* a, int n)
{
    //��С��(�����һ��Ҷ�ӽڵ�ĸ��ڵ㿪ʼ��)
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