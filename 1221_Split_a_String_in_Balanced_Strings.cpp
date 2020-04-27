/*
1221. Split a String in Balanced Strings (Easy)

https://leetcode.com/problems/split-a-string-in-balanced-strings/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split a String in Balanced Strings.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Split a String in Balanced Strings.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int countL = 0;
        for (auto i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L')
            {
                countL++;
            }
            else
            {
                countL--;
            }
            if (countL == 0)
            {
                result++;
            }
        }
        return result;
        
    }
};