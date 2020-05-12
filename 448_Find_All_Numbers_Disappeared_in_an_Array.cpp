/*
448. Find All Numbers Disappeared in an Array (Easy)

https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
Runtime: 196 ms, faster than 19.77% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 33.6 MB, less than 6.67% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int idx = 1;
        int lastnum;

        for (auto i = 0; i < nums.size(); i++)
        {
            lastnum = nums[i];
            if (nums[i] > idx)
            {
                for (auto j = idx; j < nums[i]; j++)
                {
                    result.push_back(j);
                }
                idx = nums[i];
            }
            if (nums[i] == idx)
            {
                idx++;
            }
        }
        for (auto i = lastnum + 1; i < nums.size() + 1; i++)
        {
            result.push_back(i);
        }
        return result;
        
    }
};