/*
https://leetcode.com/problems/search-insert-position/
 (Easy)
*/
#include <stdio.h>



int searchInsert(int* nums, int numsSize, int target)
{
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] == target) || (nums[i] > target))
        {
            return i;
        }
        
    }
    return i;
}

int test_case1[] = {1, 3, 5, 6};


int main()
{
    printf("num = 5; res = %d\n", searchInsert(test_case1, 4, 5));
    printf("num = 2; res = %d\n", searchInsert(test_case1, 4, 2));
    printf("num = 7; res = %d\n", searchInsert(test_case1, 4, 7));
    printf("num = 6; res = %d\n", searchInsert(test_case1, 4, 0));
    return 0;
}
