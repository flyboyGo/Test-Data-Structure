#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// int main() 
// {
//     int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
//     int i = 0;
//     int ret = arr[0];
//     for(i = 1; i < 9; i++)
//     {
//         ret = ret ^ arr[i]; 
//     }
//     printf("%d\n", ret);
//     return 0;
// }


//获取num的第n个二进制位的值
int get_bit(int num, int n)
{
    if (n == 1)
        return num & 1;
    else
        return (num >> (n - 1)) & 1;
}

//获取num的二进制位上第一个非0的位置
int get_bit_one(int num)
{
    int ret = 0, i = 0;

    while ((ret != 1) && (i <= 31))
    {
        ret = (num >> i) & 1;
        i++;
    }

    if (i == 32)
        return 0;
    else
        return i;
}

//int main()
//{
//    int arr[] = { 1, 2, 3, 4, 5, 3, 2, 1 };
//    int arr2[10] = { 0 };
//    int arr3[10] = { 0 };
//    int count2 = 0, count3 = 0;
//
//    int i = 0;
//    int ret = arr[0];
//    for (i = 1; i < 8; i++)
//    {
//        ret = ret ^ arr[i];
//    }
//
//    //获取num的二进制位上第一个非0的位置
//    int bit = 0;
//    bit = get_bit_one(ret);
//
//    for (i = 0; i < 8; i++)
//    {
//        if (get_bit(arr[i], bit) == 1)
//        {
//            arr2[count2] = arr[i];
//            count2++;
//        }
//        else if (get_bit(arr[i], bit) == 0)
//        {
//            arr3[count3] = arr[i];
//            count3++;
//        }
//    }
//
//    ret = arr2[0];
//    for (i = 1; i < count2; i++)
//    {
//        ret = ret ^ arr2[i];
//    }
//    printf("%d\n", ret);
//
//    ret = arr3[0];
//    for (i = 1; i < count3; i++)
//    {
//        ret = ret ^ arr3[i];
//    }
//    printf("%d\n", ret);
//
//    return 0;
//}


// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 6, 4, 3, 1}; // 2 5 7
//     int ret = arr[0];
//     int i = 0;
//     for(i = 1; i <11; i++)
//     {
//         ret = ret ^ arr[i];
//     }

//     //获取num的二进制位上第一个非0的位置
//     int bit = 0;
//     bit = get_bit_one(ret);

//     printf("%d\n", bit);

//     return 0;
// }



