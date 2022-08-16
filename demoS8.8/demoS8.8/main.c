#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

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

//////////////////��������

//ֱ�Ӳ�������
//ʱ�临�Ӷ�O(n^2)
//ʱ�临�Ӷȿ����������� �Ȳ����� 1+2+3+...+n-1  O(n^2)
//ʲô������? ˳������ O(n)
//�ռ临�Ӷ�ΪO(1)
//һ���ȶ��������㷨
void InsertSort(int* a, int n)
{
    //[0,end]����  end + 1λ�õ�ֵ�����ȥ,��[0, end + 1]����
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


//ϣ������(��С��������)
//ֱ���ڲ�������Ļ������Ż�
//1���Ƚ���Ԥ����,������ӽ�����
//2��ֱ�Ӳ�������(gap == 1)
//ʱ�临�Ӷ�O(nlogn)����O(nlog3n)
//ƽ����ʱ�临�Ӷ�O(n^1.3)
//���ȶ������㷨
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        //gap = gap / 3 + 1; //log3n ��3Ϊ����
        gap = gap / 2;  //log2n ��2Ϊ����
        //gap���һ�α�����1
        //gap > 1ʱ����Ԥ���� Ŀ���ǣ��ӽ�����
        //gap == 1ʱ����ֱ�Ӳ�������
        int i = 0;

        //gap�ܴ�ʱ,����Ԥ����ʱ�临�Ӷ�O(n)
        //gap��Сʱ,����ӽ�����,��ʱ���ӶȽӽ�O(n)

        //�Ѽ��Ϊgap�Ķ�������ͬʱ����
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
//    printf("%d\n", clock()); //clock()�⺯�����Ի�ȡ��ʱϵͳʱ��ĺ�����
//    return 0;
//}


