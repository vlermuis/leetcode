/*
1351. Count Negative Numbers in a Sorted Matrix (Easy)

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
Runtime: 44 ms, faster than 6.73% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (auto i = 0; i < grid.size(); i++)
        {
            sort(grid[i].begin(), grid[i].end());
            auto f = lower_bound(grid[i].begin(), grid[i].end(), 0);
            result += f - grid[i].begin();
        }
        return result;
        
    }
};