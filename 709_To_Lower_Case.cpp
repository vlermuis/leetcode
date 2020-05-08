/*
709. To Lower Case (Easy)

https://leetcode.com/problems/to-lower-case/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for To Lower Case.
*/

class Solution {
public:
    string toLowerCase(string str) {
        string alphabet = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
        for (auto i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'A') && (str[i] <= 'Z'))
            {
                auto f = find(alphabet.begin(), alphabet.end(), str[i]);
                f++;
                str[i] = *f;
            }
        }
        return str;
        
    }
};