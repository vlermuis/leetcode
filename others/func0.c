#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Write function in C to add the digits of an integer
*/
long addNumsInInt(int num)
{
    long result = 0;
    while(num > 0)
    {
        result += num % 10;
        num /= 10;
    }

    return result;
}

/*
Write a function in C to find the difference between the maximum and minimum values in an array
*/

int findDiffBetweenMaxAndMin(int* nums, int numsSize)
{
    int i;
    int max = nums[0];
    int min = nums[0];

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    return (max - min);
}
/*
 count how many bits 1 in the number
*/
int countOneBits(int num)
{
    int result = 0;
    int mask;
    int i;
    for (i = 0; i < 32; i++)
    {
        mask = 1 << i;
        if (num & mask)
        {
            result++;
        }
    }
    return result;
}

int binarySearch(int* nums, int numsSize, int val)
{
    int idx = -1;
    int right = numsSize-1;
    int left = 0;
    while(1)
    {
        idx = ((right - left)/2) + left;
        if (nums[idx] == val)
        {
            return idx;
        }
        else
        {
            if (val < nums[idx] )
            {
                right = idx - 1;
            }
            else
            {
                left = idx + 1;
            }
        }
        if (right < left)
        {
            break;
        }
    }
    return -1;
}
void swapPointers2(int** p1, int** p2)
{
    int* ptemp = *p2;
    *p2 = *p1;
    *p1 = ptemp;
}

int data[] = {12, 9, 2, 1, 4, 23, 7, 5};//8

int data2[] = {0, 1, 5, 9, 11, 23, 39, 45, 55, 99, 100}; //11
int main()
{
    int num = 0;
    printf("input the number : ");
    scanf("%d", &num);

    printf("\naddNumsInInt : %ld\n", addNumsInInt(num));

    printf("findDiffBetweenMaxAndMin : %d\n", findDiffBetweenMaxAndMin(data, 8));

    printf("countOneBits : %d\n", countOneBits(num));

    printf("binarySearch : %d\n", binarySearch(data2, 11, 33));

    int a = 35;
    int b = 99;

    int* p1 = &a;
    int* p2 = &b;

    printf("*p1:%d; *p2:%d\n", *p1, *p2);

    swapPointers2(&p1, &p2);

    printf("*p1:%d; *p2:%d\n", *p1, *p2);

    return 0;
}
