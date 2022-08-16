#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///////////////////��������
//ð������
//ʱ�临�Ӷ�O(n^2)
//���Ƚϴ��� n
//�ڲ�Ƚϴ���
//n-1
//n-2
//n-3
//������O(n)
//��ֱ�Ӳ���������ȣ� ֱ�Ӳ����������! �����򡢽ӽ����򡢾ֲ�����,ֱ�Ӳ���������Ӧ�Ը�ǿ
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

    //�ȼ���
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


//����ȡ��
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

//��������
//�ڿӷ�
int PartSort(int* a, int left, int right)
{
    //����ȡ��,����˿���������������ʱ������
    int index = GetMidIndex(a, left, right); //ȡ�м�ֵ,ͷβ������ֵ�е��м�ֵ
    Swap(&a[left], &a[index]);//�����м�ֵ��ͷ��λ��,��֤���������߼�����

    int begin = left, end = right;
    int pivot = begin;
    int key = a[begin];

    while (begin < end)//���������ʱ�临�Ӷ�ΪO(n)
    {
        //�ұ���С���ŵ����
        while (a[end] >= key && begin < end)
        {
            --end;
        }
        //С�ķŵ���ߵĿ���,�Լ��γ��µĿ�λ
        a[pivot] = a[end];
        pivot = end;

        while (a[begin] <= key && begin < end)
        {
            ++begin;
        }
        //��ķŵ��ұߵĿ���,�Լ��γ��µĿ�λ
        a[pivot] = a[begin];
        pivot = begin;
    }
    pivot = begin;
    a[pivot] = key;

    return pivot;
}

//����ָ�뷨
int PartSortPlus(int* a, int left, int right)
{
    int index = GetMidIndex(a, left, right);
    Swap(&a[left], &a[right]);

    int begin = left, end = right;
    int keyi = begin;

    while (begin < end)
    {
        //��С
        while (begin < end && a[end] >= a[keyi])
        {
            --end;
        }

        //�Ҵ�
        while (begin < end && a[begin] <= a[keyi])
        {
            ++begin;
        }

        //����
        Swap(&a[begin], &a[end]);
    }

    Swap(&a[begin], &a[keyi]);

    return begin;
}

//ǰ��ָ�뷨
int PartSortPro(int* a, int left, int right)
{
    int index = GetMidIndex(a, left, right);
    Swap(&a[left], &a[right]);

    int keyi = left;
    int prev = left, cur = left + 1;

    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur) //λ����ͬ���ý���(prev == cur)
        {
            //++prev;
            Swap(&a[cur], &a[prev]);
        }

        cur++;
    }

    Swap(&a[keyi], &a[prev]);

    return prev;
}

//��������
//�������ڲ��ȶ������򷽷�
//���������ʱ�临�Ӷ�ΪO(n)   ȡlogn�ε�keyֵ
//ʱ�临�Ӷ�O(nlogn)
//��������? ��������!  O(n^2)
void QuickSort(int* a, int left, int right)
{
    if (left >= right) //left > right���䲻����  left == right ����ֻ��һ��ֵ
        return;

    //�ڿӷ�
    //int keyIndex = PartSort(a,  left, right);

    //����ָ�뷨
    int keyIndex = PartSortPro(a, left, right);

    //[left,right]
    //[left, pivot-1] [pivot+1, right] ����������
    //���������������������,���Ǿ�������,���������������? ���εݹ�!

    //С�����Ż�,��󼸴εݹ�Ĵ����϶�,��������ݽ���,ֱ��ʹ�ò��������Ч������
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