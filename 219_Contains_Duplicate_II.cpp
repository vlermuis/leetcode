/*
219. Contains Duplicate II (Easy)

https://leetcode.com/problems/contains-duplicate-ii/
Runtime: 44 ms, faster than 44.72% of C++ online submissions for Contains Duplicate II.
Memory Usage: 16.5 MB, less than 23.53% of C++ online submissions for Contains Duplicate II.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        if (k <= 0)
        {
            return false;
        }
        if (k >= nums.size())
        {
            k = nums.size() - 1;
        }
        unordered_set<int> buff;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (i > k)
            {
                buff.erase(nums[i - k -1]);
            }
            auto f = buff.find(nums[i]);
            if (f != buff.end())
            {
                return true;
            }
            buff.insert(nums[i]);
        }
        return false;
    }
};