#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>


//��������(Ͱ����)(ֻ��������)

//��������(�ǱȽ�����)(ֻ��������)
//�����Խϴ�,ֻ��������
//ʱ�临�Ӷ�O(N+range),˵���������ڷ�Χ���е�������������
//�ռ临�Ӷ�:O(range)
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count =(int*)malloc(sizeof(int) * range);
	assert(count);

	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
		}
	}
	free(count);
}

int main(void)
{
    int data[] = { 1,3,5,7,9,2,4,6,8,10,1,8,5};
	CountSort(data, sizeof(data) / sizeof(data[0]));
    Print(data, sizeof(data) / sizeof(data[0]));
    return 0;
}