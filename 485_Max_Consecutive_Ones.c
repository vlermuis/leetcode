/*
485. Max Consecutive Ones (Easy)
https://leetcode.com/problems/max-consecutive-ones/submissions/
Runtime: 36 ms, faster than 95.16% of C online submissions for Max Consecutive Ones.
Memory Usage: 7.2 MB, less than 100.00% of C online submissions for Max Consecutive Ones.
*/



int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i;
    int m = 0;
    int prev_maxcon = 0;
    int maxcon = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            if (m == 0)
            {
                m = 1;
            }
            maxcon++;
        }
        else
        {
            m = 0;
            if (prev_maxcon < maxcon)
            {
                prev_maxcon = maxcon;
            }
            maxcon = 0;
        }
    }
    if (prev_maxcon < maxcon)
    {
        prev_maxcon = maxcon;
    }
    return prev_maxcon;

}



