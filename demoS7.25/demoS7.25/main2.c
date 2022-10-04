#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//C�����У�ÿ��ջ֡��Ӧ��һ��δ������ĺ�����ջ֡�б����˸ú����ķ��ص�ַ�;ֲ�������
//ջ֡Ҳ�й��̻��¼���Ǳ���������ʵ�ֹ���/�������õ�һ�����ݽṹ

//�ҳ�������ȱ�ٵ���ֵ
int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    int i = 0;
    //��[0, n]���
    for (i = 0; i <= numsSize; i++)
    {
        x ^= i;
    }
    //�ٸ������е�ֵ���
    for (i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }

    return x;
}
// int main()
// {
//     int arr[] = {0,1,2,3,4,5,6,8,9};
//     int ret = missingNumber(arr, 9);
//     printf("%d\n", ret);
//     return 0;
// }


//��ת����
//1���������
//2�����ٶ���Ŀռ�,�Կռ任ʱ��
//3������
void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;

        ++left;
        --right;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    if (k >= numsSize)
    {
        k = k % numsSize;
    }
    //ǰn-k��������
    reverse(nums, 0, numsSize - k - 1);
    //��k������
    reverse(nums, numsSize - k, numsSize - 1);
    //��������
    reverse(nums, 0, numsSize - 1);
}

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     rotate(arr, 9, 4);
//     int i = 0;
//     for(i = 0; i < 9; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }
