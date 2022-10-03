#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//找出num中第一个非零的二进制位
int get_one_bit(int num)
{
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        if (((num >> i) & 1) == 1)
        {
            return i + 1;
        }
    }
    return 0;
}

//找出单身数
void singleNumber(int* num, int numsSize)
{
    //求数组中所有数据异或的结果
    int i = 0, ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        ret = ret ^ num[i];
    }
    //找出ret中第一个不为零的二进制位
    int pos = get_one_bit(ret);

    //根据pos对数组中的数据进行分类
    int arr[10] = { 0 }, arr2[10] = { 0 };
    int count = 0, count2 = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (get_one_bit(num[i]) == pos)
        {
            arr[count] = num[i];
            count++;
        }
        else
        {
            arr2[count2] = num[i];
            count2++;
        }
    }
    //根据分类的结果,算出单身数
    ret = 0;
    for (i = 0; i < count; i++)
    {
        ret = ret ^ arr[i];
    }
    printf("%d ", ret);
    ret = 0;
    for (i = 0; i < count2; i++)
    {
        ret = ret ^ arr2[i];
    }
    printf("%d ", ret);

}

// int main(void) 
// {
//     int arr[] = {1,2,3,5,5,6,4,3,2,1};
//     singleNumber(arr, 10);
//     return 0;
// }


//删除数组中指定的数据
//改进版,时间复杂度为O(n^2),空间复杂度为O(n)
int removeElement(int* nums, int numsSize, int val)
{
    int count = 1, tmp = 0;
    while (count < numsSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i; j < numsSize - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                numsSize--;
            }
        }
        count++;
    }
    return numsSize;
}

//改进版,时间复杂度为O(n),空间复杂度为O(n)
int removeElementPlus(int* nums, int numsSize, int val)
{
    int count = 0, i = 0;
    int* tmp = (int*)malloc(sizeof(int) * numsSize);

    //找出不是删除的数据,保存到临时数组中
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            tmp[count] = nums[i];
            count++;
        }
    }
    //复制符合的数据
    for (i = 0; i < count; i++)
    {
        nums[i] = tmp[i];
    }
    return count;
}

//加强版,空间复杂度为O(1),时间复杂度为O(n)
int removeElementMax(int* nums, int numsSize, int val)
{
    int dst = 0, i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[dst] = nums[i];
            dst++;
        }
    }
    return dst;
}

// int main()
// {
//     int arr[] = {1, 2, 3, 3, 4, 5, 6};
//     int i = 0;
//     int ret = removeElementMax(arr, 7, 3);
//     printf("%d\n", ret);
//     for(i = 0; i < ret; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }


//去重(无序)
int removeDuplicates(int* nums, int numsSize)
{
    int i = 0, j = 0, count = 0;
    int flag = 1;
    int* tmp = (int*)malloc(sizeof(int) * numsSize);

    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < count; j++)
        {
            if (tmp[j] == nums[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            tmp[count] = nums[i];
            count++;
        }
        flag = 1;
    }

    for (i = 0; i < count; i++)
    {
        nums[i] = tmp[i];
    }

    return count;
}

//去重(有序),三指针
int removeDuplicatesPlus(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int i = 0, j = 1;
    int dst = 0;
    while (j < numsSize)
    {
        if (nums[i] == nums[j])
        {
            ++j;
        }
        else
        {
            nums[dst] = nums[i];
            ++dst;
            i = j;
            ++j;
        }
    }
    nums[dst] = nums[i];
    ++dst;

    return dst;
}

//去重(有序),双指针
int removeDuplicatesMax(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int i = 0, j = 0;
    while (j < numsSize)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return (i + 1);
}

// int main()
// {
//     int arr[] = {1, 2, 3, 3, 4, 5, 5, 6};
//     int ret = removeDuplicatesMax(arr, 8);
//     int i = 0;
//     for(i = 0; i < ret; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

int merge(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0, j = 0, k = 0;
    int* pf = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    for (k = 0; (i < nums1Size && j < nums2Size); k++)
    {
        if (nums1[i] < nums2[j])
        {
            pf[k] = nums1[i];
            i++;
        }
        else if (nums1[i] >= nums2[j])
        {
            pf[k] = nums2[j];
            j++;
        }
    }

    if (i != nums1Size)
    {
        for (; i < nums1Size; i++)
        {
            pf[k] = nums1[i];
            k++;
        }
    }
    else if (j != nums2Size)
    {
        for (; j < nums2Size; j++)
        {
            pf[k] = nums2[j];
            k++;
        }
    }

    for (i = 0; i < k; i++)
    {
        nums1[i] = pf[i];
    }

    return k;
}

int mergePlus(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = nums1Size - 1, j = nums2Size - 1, k = nums1Size + nums2Size - 1;

    for (k = nums1Size + nums2Size - 1; (i >= 0 && j >= 0); k--)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else if (nums1[i] <= nums2[j])
        {
            nums1[k] = nums2[j];
            j--;
        }
    }

    if (j != 0)
    {
        for (; j > 0; j--)
        {
            nums1[k] = nums2[j];
            k--;
        }
    }

    return (nums1Size + nums2Size - 1);
}

int main()
{
    int arr[12] = { 1,3,3,5,7,9 };
    int arr2[6] = { 2,4,4,6,8,10 };
    int ret = mergePlus(arr, 6, arr2, 6);
    int i = 0;
    for (i = 0; i < ret; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
