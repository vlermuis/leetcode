/*
442. Find All Duplicates in an Array (Medium)

https://leetcode.com/problems/find-all-duplicates-in-an-array/
Runtime: 192 ms, faster than 20.09% of C++ online submissions for Find All Duplicates in an Array.
Memory Usage: 33.5 MB, less than 5.00% of C++ online submissions for Find All Duplicates in an Array.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        if (nums_size > 2)
        {
            for (auto i = 0; i < nums_size-2; i++)
            {
                if ((nums[i] == nums[i+1]) && (nums[i] != nums[i+2]))
                {
                    result.push_back(nums[i]);
                    i++;
                }
            }
            if ((nums[nums_size-1] == nums[nums_size-2]) && (nums[nums_size-2] != nums[nums_size-3]))
            {
                result.push_back(nums[nums_size-1]);
            }

        } else
        {
            if (nums_size == 2)
            {
                if (nums[0] == nums[1])
                {
                    result.push_back(nums[0]);
                }
            }
        }

        return result;
        
    }
};