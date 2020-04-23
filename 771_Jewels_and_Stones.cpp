/*
771. Jewels and Stones (Easy)

https://leetcode.com/problems/jewels-and-stones/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Jewels and Stones.
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for (auto i = 0; i < J.length(); i++)
        {
            auto start_idx = 0;
            auto f = S.find(J[i],start_idx);
            if (f != string::npos)
            {
                while(f != string::npos)
                {
                    result++;
                    start_idx = f + 1;
                    f = S.find(J[i],start_idx);
                }
            }
        }
        return result;
        
    }
};