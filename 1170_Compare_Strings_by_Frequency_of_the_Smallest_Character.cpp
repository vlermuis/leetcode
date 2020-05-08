/*
1170. Compare Strings by Frequency of the Smallest Character (Easy)

https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
Runtime: 24 ms, faster than 77.99% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
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
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> result;
        vector<int> words_cf;
        for (auto i = 0; i < words.size(); i++)
        {
            words_cf.push_back(funcF(words[i]));
        }
        sort(words_cf.begin(), words_cf.end());
        for (auto i = 0; i < queries.size(); i++)
        {
            auto f = upper_bound(words_cf.begin(), words_cf.end(), funcF(queries[i]));
            result.push_back(words_cf.end() - f);
        }

        return result;
        
    }
};