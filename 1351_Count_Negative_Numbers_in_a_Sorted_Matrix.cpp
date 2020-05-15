/*
1351. Count Negative Numbers in a Sorted Matrix (Easy)

https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
Runtime: 28 ms, faster than 30.87% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);        
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