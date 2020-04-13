/*
162. Find Peak Element (Medium)
https://leetcode.com/problems/find-peak-element/

Runtime: 4 ms, faster than 95.99% of C++ online submissions for Find Peak Element.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Find Peak Element.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
             return 0;
        }
        if (nums.size() == 2)
        {
            if (nums.front() > nums.back())
                return 0;
            else
                return 1;
        }
        auto i = nums.begin();
        i++;
        if (nums.front() > * i)
        {
            return 0;
        }
        i = nums.end();
        i -= 2;
        if (nums.back() > *i)
        {
            int pos = distance(nums.begin(), i);
            pos++;
            return pos;
        }
        for (auto itr = nums.begin()+1; itr != nums.end()-1; itr++)
        {
            auto prev_itr = itr - 1;
            auto next_itr = itr + 1;
            if ((*prev_itr < *itr) && (*next_itr < *itr))
            {
                int pos = distance(nums.begin(), itr);
                return pos;
            }
        }
        return -1;
    }
};