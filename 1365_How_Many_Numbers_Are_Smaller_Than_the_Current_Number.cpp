/*
1365. How Many Numbers Are Smaller Than the Current Number (Easy)

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
Runtime: 8 ms, faster than 99.69% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
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
        int counts[101] = {0};

        for(auto& num : nums)
        {
            counts[num]++;
        }
        int sum = 0;
        for (auto i = 0; i < 101; i++)
        {
            sum += counts[i];
            counts[i] = sum;
        }
        int res[1024] = {0};
        for (auto i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                result.push_back(counts[nums[i]-1]);
                res[i] = counts[nums[i]-1];
            }
            else
            {
                result.push_back(0);
                res[i] = 0;
            }
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


