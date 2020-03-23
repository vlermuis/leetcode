/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
1342. Number of Steps to Reduce a Number to Zero (Easy)
Runtime: 0 ms, faster than 100.00% of C online submissions for Number of Steps to Reduce a Number to Zero.
Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Number of Steps to Reduce a Number to Zero.
*/

int numberOfSteps (int num){
    int idx = 0;
    while (num > 0)
    {
        if ( 1 & num)
        {
            num--;
        }
        else
        {
            num = num >> 1;
        }
        idx++;
    }
    return idx;

}

