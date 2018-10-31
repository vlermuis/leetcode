/*
* 137. Single Number II (Medium)
* https://leetcode.com/problems/single-number-ii/description/
*
*/
bool isElementThereFreeTimes(int* nums, int element, int numSize)
{
    int i = 0;
    int hmt = 0;
    for (i = 0; i < numSize; i++)
    {
        if (nums[i] == element)
        {
            if (hmt == 2)
            {
                return true;
            }
            else
            {
                hmt++;
            }
        }
    }
    return false;
}

int singleNumber(int* nums, int numsSize) {

    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (!isElementThereFreeTimes(nums, nums[i], numsSize))
        {
            return nums[i];
        }
    }
    return 0;
}
