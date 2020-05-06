/*
75. Sort Colors (Medium)

https://leetcode.com/problems/sort-colors/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
Memory Usage: 8.6 MB, less than 89.47% of C++ online submissions for Sort Colors.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colorcounts{0,0,0};
        for (auto i = 0; i < nums.size(); i++)
        {
            colorcounts[nums[i]]++;
        }
        int idx = 0;
        for (auto x = 0; x < 3; x++)
        {
            for (auto i = 0; i < colorcounts[x]; i++, idx++)
            {
                nums[idx] = x;
            }
        }
    }
};
int main()
{
    vector<int> v{2,0,2,1,1,0};

    Solution solution;
    solution.sortColors(v);
    for (auto x : v)
    {
        cout << x << ", ";
    }
    cout << "\n";

    return 0;
}
