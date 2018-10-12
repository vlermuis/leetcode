/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

https://leetcode.com/submissions/detail/153123345/
*/
void shift_array(int* array, int size)
{
    int i = 0;
    for ( i = 1; i < size; i++)
    {
        array[i-1] = array[i];
    }
}

int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int dup = nums[0];
    bool flag = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (dup == nums[i])
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                shift_array(&nums[i], (numsSize - i));
                numsSize--;
                i--;
            }
        }
        else
        {
            flag = false;
            dup = nums[i];
        }
    }
    return numsSize;
}
