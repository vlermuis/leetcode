/*
https://leetcode.com/problems/single-number/description/
https://leetcode.com/submissions/detail/153449812/
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

int singleNumber(int* nums, int numsSize) {
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (!isElementThereTwice(nums, nums[i], numsSize))
        {
            return nums[i];
        }
    }
   return 0;
}