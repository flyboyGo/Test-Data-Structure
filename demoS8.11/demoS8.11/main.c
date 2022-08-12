#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

//�ݹ��ȱ��:��ĳЩ���������,���ڵݹ�����̫��,ջ�жѻ���̫��ĺ�����ջ֡�޷���ʱ�ͷ�,
//�ᵼ��ջ�ռ䲻����,���ܻ������
//�ǵݹ�
//�ݹ�ķǵݹ�: 1��ֱ�Ӹ�ѭ�� 2���������ݽṹģ��ݹ����(����һ��)

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
void Swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//��ӡ����
void Print(int* a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

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

//����(�ǵݹ�)
//��ջģ��ݹ�(����Ҳ����)
void QuickSortNonR(int* a, int n)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, n - 1);
    StackPush(&st, 0);

    while (!StackEmpty(&st))
    {
        int left = StackTop(&st);//ȡջ��Ԫ��,�ȵõ����±�
        StackPop(&st);

        int right = StackTop(&st);//ȡջ��Ԫ��,��õ����±�
        StackPop(&st);

        int keyIndex = PartSort(a, left, right);

        //[left, keyIndex - 1] [keyIndex + 1, right] �ָ�����������

        //����������
        if (keyIndex + 1 < right)
        {
            StackPush(&st, right); //�������±�
            StackPush(&st, keyIndex + 1);//�������±�
        }

        //����������
        if (left < keyIndex - 1)
        {
            StackPush(&st, keyIndex - 1); 
            StackPush(&st, left);
        }
    }

    StackDestory(&st);
}


//�鲢����(�ǵݹ�)(�˷��������ڶ���Ч��)
//ʱ�临�Ӷ�O(nlogn)
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);

    int gap = 1;//ÿ�����ݸ���
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap)
        {
            //[i, i+gap-1] [i+gap, i+2*gap-1]

            int begin1 = i, end1 = i + gap - 1; 
            int begin2 = i + gap, end2 = i + 2 * gap - 1;

            //�鲢��������������ܾͲ�����
            //�������,ֻ����ÿ���ڲ�鲢ѭ�������һ�ο��ܳ���
            //�����䲻����,����������,����鲢,ֱ�ӽ���
            if (begin2 >= n)
            {
                break;
            }

            //�鲢���������������,����������
            //�������,ֻ����ÿ���ڲ�鲢ѭ�������һ�ο��ܳ���
            //��������
            if (end2 >= n)
            {
                end2 = n - 1;
            }

            //�鲢���������������,����������,
            //�������,ֻ����ÿ���ڲ�鲢ѭ�������һ�ο��ܳ���
            //���������,����������,������,��ʱ������һ��������,���账��(����鲢������)

            int index = i;
            //��ʼ�鲢
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

            //�鲢ʣ������
            while (begin1 <= end1)
            {
                tmp[index++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                tmp[index++] = a[begin2++];
            }

            //��������
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
