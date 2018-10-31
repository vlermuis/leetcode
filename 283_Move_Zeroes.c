/*
* 283. Move Zeroes (Easy)
* https://leetcode.com/problems/move-zeroes/description/
*
*
*/

void shift_array(int * a, int start_idx, int len)
{
    int i;
    for (i = start_idx; i < len -1; i++)
    {
        a[i] = a[i+1];
    }

}

void moveZeroes(int* nums, int numsSize) {
    int i;
    int zero_idx = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            shift_array(nums, i, numsSize);
            zero_idx++;
            numsSize--;
            i--;
        }
    }
    for (i = 0; i < zero_idx; i++)
    {
        nums[numsSize + i] = 0;
    }

}