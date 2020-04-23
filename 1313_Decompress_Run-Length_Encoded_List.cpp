/*
1313. Decompress Run-Length Encoded List (Easy)

https://leetcode.com/problems/decompress-run-length-encoded-list/
Runtime: 44 ms, faster than 78.00% of C++ online submissions for Decompress Run-Length Encoded List.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (auto i = 0; i < nums.size(); i+=2)
        {
            int repeats = nums[i];
            int val = nums[i+1];
            for (auto j = 0; j < repeats; j++)
            {
                result.push_back(val);
            }

        }
       return result;
        
    }
};