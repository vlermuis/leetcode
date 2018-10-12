
/*
https://leetcode.com/problems/remove-element/description/

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


int removeElement(int* nums, int numsSize, int val) {
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            shift_array(nums, i, numsSize);
            numsSize--;
            i--;
        }
    }
    return numsSize;
}
