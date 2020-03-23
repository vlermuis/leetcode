/*
260. Single Number III (Medium)
https://leetcode.com/problems/single-number-iii/submissions/
Medium
Runtime: 136 ms, faster than 11.11% of C online submissions for Single Number III.
Memory Usage: 6.7 MB, less than 100.00% of C online submissions for Single Number III.

*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isElementThereTwice(int* nums, int element, int numSize)
{
    int i = 0;
    bool bIsFirstFind = false;
    for (i = 0; i < numSize; i++)
    {
        if (nums[i] == element)
        {
            if (bIsFirstFind)
            {
                return true;
            }
            else
            {
                bIsFirstFind = true;
            }
        }
    }
    return false;
}

int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int* result = (int*)malloc(sizeof(int)*2);
    int idx = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (!isElementThereTwice(nums, nums[i], numsSize))
        {
            result[idx] = nums[i];
            idx++;
            if (idx == 2)
            {
                break;
            }
        }
    }
    *returnSize = 2;
    return result;
}