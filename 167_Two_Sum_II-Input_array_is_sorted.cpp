/*
167. Two Sum II - Input array is sorted (Easy)

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Runtime: 4 ms, faster than 94.22% of C++ online submissions for Two Sum II - Input array is sorted.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Two Sum II - Input array is sorted.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         vector<int> result;
         int r = numbers.size() -1;
         int l = 0;
         while (l < r)
         {
             if (numbers[l] + numbers[r] == target)
             {
                 result.push_back(l+1);
                 result.push_back(r+1);
                 return result;
             } else if (numbers[l] + numbers[r] < target)
             {
                 l++;
             } else
             {
                 r--;
             }
         }
         return result;
        
    }
};