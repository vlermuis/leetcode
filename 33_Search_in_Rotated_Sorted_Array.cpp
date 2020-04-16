/*

33. Search in Rotated Sorted Array (Medium)
https://leetcode.com/problems/search-in-rotated-sorted-array/ 
Runtime: 4 ms, faster than 69.01% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left;
        int right;

        left = 0;
        right = nums.size() -1;
        while ( left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] >= nums[left])
            {
                if ((target <= nums[mid]) && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if ((target > nums[mid]) && (target <= nums[right]))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

        }

        return -1;
    }
};
int main()
{
    vector<int> v{4,5,6,7,0,1,2};
    Solution solution;
    cout << solution.search(v, 0) << endl;

//    cout << "[" << r[0] << " : " << r[1] << "]" << endl;
    return 0;
}

