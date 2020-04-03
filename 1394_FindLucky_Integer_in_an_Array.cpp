/*
1394. Find Lucky Integer in an Array (Easy)
Runtime: 44 ms, faster than 6.12% of C++ online submissions for Find Lucky Integer in an Array.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Find Lucky Integer in an Array.

https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/

*/

#include <bits/stdc++.h>

class Solution {
private:
    int getFreq(vector<int>& arr, int n)
    {
        int freq = 0;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] == n)
            {
                freq++;
            }
        }
        return freq;
    }
public:
    int findLucky(vector<int>& arr) {
        vector<int> lucky_nums;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] == getFreq(arr, arr[i]))
            {
                lucky_nums.push_back(arr[i]);
            }
        }
        if (lucky_nums.size() > 0)
        {
            sort(lucky_nums.begin(), lucky_nums.end(), greater<int>());
            return lucky_nums[0];
        }
        else
        {
            return -1;
        }
    }
};