/*
434. Number of Segments in a String (Easy)

https://leetcode.com/problems/number-of-segments-in-a-string/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Segments in a String.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Number of Segments in a String.
*/

class Solution {
public:
    int countSegments(string s) {
        int idx = 0;
        int result = 0;
        bool bIsWord = false;
        while(idx < s.length())
        {
            if (s[idx] == ' ')
            {
                bIsWord = false;
            }
            if ((s[idx] != ' ') && (!bIsWord))
            {
                bIsWord = true;
                result++;
            }
            idx++;
        }
        return result;
    }
};