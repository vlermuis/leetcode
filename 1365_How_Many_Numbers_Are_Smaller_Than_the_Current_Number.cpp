/*
1365. How Many Numbers Are Smaller Than the Current Number (Easy)

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
Runtime: 56 ms, faster than 13.40% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
*/

#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for (auto i = 0; i < nums.size(); i++)
        {
            int r = 0;
            for (auto j = 0; j < nums.size(); j++)
            {
                if ((i != j) && (nums[j] < nums[i]))
                    {
                        r++;
                    }
            }
            result.push_back(r);
        }
        return result;
    }
};

int main()
{
    vector<int> v{8,1,2,2,3};
    vector<int> v1{6,5,4,8};
    vector<int> v2{7,7,7,7};
    vector<int> v3{};
    Solution solution;
    vector<int> r = solution.smallerNumbersThanCurrent(v);
    for (auto x : r)
    {
        cout << x << ", ";
    }
    cout << "\n";
    r = solution.smallerNumbersThanCurrent(v1);
    for (auto x : r)
    {
        cout << x << ", ";
    }
    cout << "\n";
    r = solution.smallerNumbersThanCurrent(v2);
    for (auto x : r)
    {
        cout << x << ", ";
    }
    cout << "\n";
    r = solution.smallerNumbersThanCurrent(v3);
    for (auto x : r)
    {
        cout << x << ", ";
    }
    cout << "\n";
	return 0;
}


