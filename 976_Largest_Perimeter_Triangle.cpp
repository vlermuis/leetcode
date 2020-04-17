/*
976. Largest Perimeter Triangle (Easy)
https://leetcode.com/problems/largest-perimeter-triangle/
Runtime: 88 ms, faster than 9.79% of C++ online submissions for Largest Perimeter Triangle.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Largest Perimeter Triangle.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& A)
    {
        sort(A.begin(), A.end(), greater<int>());

        int start_idx = 0;

        while (start_idx < (A.size()-2))
        {
            int i = start_idx + 2;


            while ((A[start_idx] >= (A[start_idx + 1] + A[i])) && (i < A.size()-1))
            {
                i++;
            }
            int a0 = A[start_idx];
            int a1 = A[start_idx + 1];
            int ai = A[i];

            if ((A[start_idx] < (A[start_idx + 1] + A[i])) || (A[start_idx] == A[start_idx + 1]))
            {
                return (A[start_idx] + A[start_idx + 1] + A[i]);
            }
            start_idx++;
        }
        return 0;
    }
};

int main()
{
    vector<int> v{2,4,2,1};
    vector<int> v1{2,1,2};
    vector<int> v2{1,2,1};
    vector<int> v3{3,2,3,4};
    vector<int> v4{3,6,2,3};
    Solution solution;
    cout << solution.largestPerimeter(v) << endl;
    cout << solution.largestPerimeter(v1) << endl;
    cout << solution.largestPerimeter(v2) << endl;
    cout << solution.largestPerimeter(v3) << endl;
    cout << solution.largestPerimeter(v4) << endl;

    return 0;
}
