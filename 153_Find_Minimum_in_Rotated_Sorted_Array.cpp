/*
153. Find Minimum in Rotated Sorted Array (Medium)
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


/*
Runtime: 4 ms, faster than 61.05% of C++ online submissions for Find Minimum in Rotated Sorted Array.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted
*/
class _Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums.front();
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left;
        int right;
        left = 0;
        right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }

            if (nums[mid] > nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
    return nums[left];
    }
};

int main()
{
    vector<int> v{3,4,5,1,2};
    Solution solution;
    cout << solution.findMin(v) << endl;

//    cout << "[" << r[0] << " : " << r[1] << "]" << endl;
    return 0;
}

