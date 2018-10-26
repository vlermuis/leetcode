/*
* 371. Sum of Two Integers (Easy)
* https://leetcode.com/problems/sum-of-two-integers/description/
*
*/

int getSum(int a, int b) {
    int carry = 0;
    int result = 0;
    int i;

    for(i = 0; i < 32; ++i) {
        int x = (a >> i) & 1;
        int y = (b >> i) & 1;
        result |= ((x ^ y) ^ carry) << i;
        carry = (x & y) | (y & carry) | (carry & x);
    }

    return result;
}

