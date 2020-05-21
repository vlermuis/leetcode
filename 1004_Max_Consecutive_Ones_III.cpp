/*
1004. Max Consecutive Ones III (Medium)

https://leetcode.com/problems/max-consecutive-ones-iii/
Runtime: 136 ms, faster than 39.10% of C++ online submissions for Max Consecutive Ones III.
Memory Usage: 55.5 MB, less than 9.09% of C++ online submissions for Max Consecutive Ones III.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>

using namespace std;


void display_vect(vector<double> v)
{
    for (auto x : v)
    {
        cout << x << ", ";
    }
    cout << "\n";
}


/*
 * For each A[j], try to find the longest subarray.
 * If A[i] ~ A[j] has zeros <= K, we continue to increment j.
 * If A[i] ~ A[j] has zeros > K, we increment i.
 * */
class Solution {
public:
    int _longestOnes(vector<int>& A, int K) {
        int i = 0, j;
        for (j = 0; j < A.size(); ++j)
        {
            if (A[j] == 0)
            {
                K--;
            }
            if (K < 0 && A[i++] == 0)
            {
                K++;
            }
        }
        return j - i;
    }
    int longestOnes(vector<int>& A, int K) {
        int zeros = 0;
        int windowstart = 0;
        int windowend = 0;
        for (windowend = 0; windowend < A.size(); windowend++)
        {
            if (A[windowend] == 0)
            {
                zeros++;
            }
            if (zeros > K && A[windowstart++] == 0)
            {
                //windowstart++;
                zeros--;
            }

        }
        return (windowend - windowstart);
    }
};

int main() {
/*    vector<int> t{1,2,3,};
    int i = 0;
    if (true  && t[i] == 1)
    {
        i++;
        cout << "condition\n";
    }
*/


    Solution solution;
    vector<int> v{1,1,1,0,0,0,1,1,1,1,0};
    cout << solution.longestOnes(v, 2) << "\n";


    return 0;
}
