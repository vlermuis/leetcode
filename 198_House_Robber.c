/*
* 198. House Robber (Easy)
* https://leetcode.com/problems/house-robber/description/
* 
*
*/

int rob(int* nums, int numsSize) {

    if (numsSize == 0)
    {
        return 0;
    }
    int i = 0;
    int pmarks[numsSize];
    pmarks[0] = nums[0];

    if (numsSize < 2)
    {
        return pmarks[0];
    }
    else
    {
        if (nums[1] > nums[0])
        {
            pmarks[1] = nums[1];
        }
        else
        {
            pmarks[1] = nums[0];
        }
        for (i = 2; i < numsSize; i++)
        {
            int temp = nums[i] + pmarks[i-2];
            int temp1 = pmarks[i-1];
            if (temp > temp1)
            {
                pmarks[i] = temp;
            }
            else
            {
                pmarks[i] = temp1;
            }
        }
        return pmarks[numsSize-1];
    }
}

