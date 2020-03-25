/*

https://leetcode.com/problems/plus-one/
66. Plus One (Easy)

Runtime: 0 ms, faster than 100.00% of C online submissions for Plus One.
Memory Usage: 5.6 MB, less than 100.00% of C online submissions for Plus One.

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void reverse_array(int* nums, int numsSize)
{
    int i;
    for (i = 0; i < numsSize/2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = temp;
    }
}

 
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*(digitsSize + 1));
    int i;

    reverse_array(digits, digitsSize);

    int temp = digits[0] + 1;
    int nextr = 0;
    if (temp > 9)
    {
        nextr = 1;
        result[0] = temp - 10;
    }
    else
    {
        result[0]  = temp;
    }
    for (i = 1; i < digitsSize; i++)
    {
        temp = digits[i] + nextr;
        if (temp > 9)
        {
            nextr = 1;
            result[i] = temp - 10;
        }
        else
        {
            nextr = 0;
            result[i] = temp;
        }
    }
    if (nextr == 1)
    {
        result[digitsSize] = 1;
        reverse_array(result, digitsSize+1);
        *returnSize = digitsSize + 1;
    }
    else
    {
        reverse_array(result, digitsSize);
        *returnSize = digitsSize;
    }

    return result;

}

