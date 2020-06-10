/*
1470. Shuffle the Array (Easy)

https://leetcode.com/problems/shuffle-the-array/
Runtime: 12 ms, faster than 74.19% of C++ online submissions for Shuffle the Array.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Shuffle the Array.
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for (auto i = 0; i < n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[i + n]);
        }
        return result;
    }
};
