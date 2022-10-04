#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//C语言中，每个栈帧对应着一个未运行完的函数。栈帧中保存了该函数的返回地址和局部变量。
//栈帧也叫过程活动记录，是编译器用来实现过程/函数调用的一种数据结构

//找出数组中缺少的数值
int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    int i = 0;
    //跟[0, n]异或
    for (i = 0; i <= numsSize; i++)
    {
        x ^= i;
    }
    //再跟数组中的值异或
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


//旋转数组
//1、暴力求解
//2、开辟额外的空间,以空间换时间
//3、逆置
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
    //前n-k个数逆置
    reverse(nums, 0, numsSize - k - 1);
    //后k个逆置
    reverse(nums, numsSize - k, numsSize - 1);
    //整体逆置
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
