/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
easy
*/
void shift_array(int * a, int start_idx, int len)
{
    int i;
    for (i = start_idx; i < len -1; i++)
    {
        a[i] = a[i+1];
    }

}

int removeDuplicates(int* nums, int numsSize) {
    int i;
    bool bIsAtLeastOnce = false;
    if (numsSize < 2)
    {
        return numsSize;
    }
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            bIsAtLeastOnce = true;
            shift_array(nums, i, numsSize);
            numsSize--;
            i--;
        }
    }
    if (bIsAtLeastOnce)
    {
        return numsSize+1;
    }
    else
    {
        return numsSize;
    }
}