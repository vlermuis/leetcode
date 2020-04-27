/*
1295. Find Numbers with Even Number of Digits (Easy)

https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
Runtime: 8 ms, faster than 54.92% of C++ online submissions for Find Numbers with Even Number of Digits.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Find Numbers with Even Number of Digits.
*/

class Solution {
public:
    int numberDigits(int n)
    {
        int result = 0;
        while(n > 0)
        {
            n  /= 10;
            result++;
        }
        return result;
    }
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (numberDigits(nums[i]) % 2 == 0)
            {
                result++;
            }
        }
        return result;
    }
};
