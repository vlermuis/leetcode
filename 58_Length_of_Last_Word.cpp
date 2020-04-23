/*
58. Length of Last Word (Easy)
https://leetcode.com/problems/length-of-last-word/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Length of Last Word.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int idx = s.length() - 1;

        while ((idx >= 0) && (s[idx] == ' '))
        {
            idx--;
        }
        while ((idx >= 0) && (s[idx] != ' '))
        {
            idx--;
            result++;
        }
        return result;
    }
};