/*
1170. Compare Strings by Frequency of the Smallest Character (Easy)

https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
Runtime: 32 ms, faster than 59.20% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
*/

class Solution {
public:
    int funcF(string str)
    {
        if (str.length() == 0)
        {
            return 0;
        }
        sort(str.begin(), str.end());
        int idx = 0;
        while((str[idx] == str[idx + 1]) && (idx < str.length()))
        {
            idx++;
        }
        idx++;
        return idx;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        vector<int> queries_cf;
        vector<int> words_cf;
        for (auto i = 0; i < queries.size(); i++)
        {
            queries_cf.push_back(funcF(queries[i]));
        }
        for (auto i = 0; i < words.size(); i++)
        {
            words_cf.push_back(funcF(words[i]));
        }
        sort(words_cf.begin(), words_cf.end());
        for (auto i = 0; i < queries_cf.size(); i++)
        {
            auto f = upper_bound(words_cf.begin(), words_cf.end(), queries_cf[i]);
            result.push_back(words_cf.end() - f);
        }

        return result;
        
    }
};