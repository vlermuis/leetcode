/*
https://leetcode.com/problems/number-complement/ 
476. Number Complement (Easy)

Runtime: 0 ms, faster than 100.00% of C online submissions for Number Complement.
Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Number Complement.
*/
int findComplement(int num){
    int numc = num;
    int idx = 0;
    int i;
    while (numc > 0)
    {
        numc = numc >> 1;
        idx++;
    }
    for (i = 0; i < idx; i++)
    {
        num ^= (1 << i);
    }
    return num;

}

