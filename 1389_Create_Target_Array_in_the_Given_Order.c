/*
1389. Create Target Array in the Given Order (Easy)
https://leetcode.com/problems/create-target-array-in-the-given-order/submissions/
Runtime: 0 ms, faster than 100.00% of C online submissions for Create Target Array in the Given Order.
Memory Usage: 5.7 MB, less than 100.00% of C online submissions for Create Target Array in the Given Order.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void shift_right(int* nums, int numsSize, int pos)
{
    int i;
    for (i = numsSize-2; i >= pos; i--)
    {
        nums[i+1] = nums[i];
    }
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
   int* result = (int*)malloc(sizeof(int)*numsSize);
   int r_size = 0;
   int i;
   for (i = 0; i < numsSize; i++)
   {
       shift_right(result, numsSize, index[i]);
       result[index[i]] = nums[i];
   }
   *returnSize = numsSize;
   return result;
}

