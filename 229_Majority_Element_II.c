/*
* 229. Majority Element II (Medium)
* https://leetcode.com/problems/majority-element-ii/description/
*/

int tin_array(int* array, int size, int element)
{
    int i = 0;
    int n = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            n++;
        }
    }
    return n;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int* ppp = (int*)malloc(sizeof(int)*2);
    int* ppp0 = ppp;
    int idx = 0;
    for (i = 0; i < numsSize; i++)
    {
        int n = tin_array(nums, numsSize, nums[i]);
        if (n > (numsSize/3))
        {
            if (idx == 0)
            {
                *ppp = nums[i];
                idx++;
                ppp++;
            }
            else if (idx == 1)
            {
                if (nums[i] != *ppp0)
                {
                    *ppp = nums[i];
                    idx++;
                    ppp++;
                    *returnSize = 2;
                    return ppp0;
                }
            }
        }
    }
    *returnSize = idx;
    return ppp0;
}
