/*
1395. Count Number of Teams (Medium)

https://leetcode.com/problems/count-number-of-teams/
Runtime: 4 ms, faster than 99.09% of C++ online submissions for Count Number of Teams.
Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Count Number of Teams.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * for each soldier i calculate how many have less and greater ratings on the left and right
     *  then for him number of teams will be : ((leftless * rightgreat) + (leftgreat * rightless));
     */
    int numTeams(vector<int>& rating) {
        int result = 0;
        int leftless = 0;
        int leftgreat = 0;
        int rightless = 0;
        int rightgreat = 0;
        for (auto i = 1; i < rating.size()-1; i++)
        {
            leftless = 0;
            leftgreat = 0;
            rightless = 0;
            rightgreat = 0;
            for (auto j = 0; j < rating.size(); j++)
            {
                if ((j < i) && (rating[j] < rating[i]))
                {
                    leftless++;
                }
                if ((j < i) && (rating[j] > rating[i]))
                {
                    leftgreat++;
                }
                if ((j > i) && (rating[j] < rating[i]))
                {
                    rightless++;
                }
                if ((j > i) && (rating[j] > rating[i]))
                {
                    rightgreat++;
                }
            }
            result += ((leftless * rightgreat) + (leftgreat * rightless));
        }


        return result;
    }
};

int main()
{
    vector<int> v{2,5,3,4,1};
    vector<int> v1{2,1,3};
    vector<int> v2{1,2,3,4};
    Solution solution;
    cout << solution.numTeams(v) << "\n";
    cout << solution.numTeams(v1) << "\n";
    cout << solution.numTeams(v2) << "\n";
    return 0;
}
