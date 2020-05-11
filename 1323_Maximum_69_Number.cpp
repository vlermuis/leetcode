/*
1323. Maximum 69 Number (Easy)

https://leetcode.com/problems/maximum-69-number/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Maximum 69 Number.
*/
class Solution {
public:
    int tenstep(int n)
    {
        int result = 1;
        for (auto i = 0; i < n; i++)
        {
            result *= 10;
        }
        return result;
    }
    
    int maximum69Number (int num) {
        vector<int> digit;
        int result = 0;
        while (num > 0)
        {
            digit.insert(digit.begin(), (num % 10));
            num /= 10;
        }
        for (auto i = 0; i < digit.size(); i++)
        {
            if (digit[i] == 6)
            {
                digit[i] = 9;
                break;
            }
        }
        int i,j;
        for (i = digit.size()-1, j = 0; i >= 0; i--, j++)
        {
            result += (digit[i] * (tenstep(j)));
        }

        return result;
        
    }
};