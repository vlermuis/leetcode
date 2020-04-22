/*
3. Longest Substring Without Repeating Characters (Medium)
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Runtime: 1524 ms, faster than 5.10% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 34.4 MB, less than 9.95% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        for (auto i = 0; i < s.size(); i++)
        {
            vector<char> c;
            c.clear();
            for (auto j = i; j < s.size(); j++)
            {
                auto f = find(c.begin(),c.end(),s[j]);
                if (f != c.end())
                {
                    break;
                }
                else
                {
                    c.push_back(s[j]);
                }
            }
            if (result < c.size())
            {
                result = c.size();
            }
            cout << endl;
        }
        return result;
   
    }
};