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
 * Sliding window approach
 * Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
 * */
class Solution {
public:

    vector<double> AverageContSubArr(vector<int> arr, int k)
    {
        vector<double> result;
        double wsum = 0;
        int wstart = 0;
        for (auto wend = 0; wend < arr.size(); wend++)
        {
            wsum += arr[wend];
            if (wend >= k - 1)
            {
                result.push_back((wsum / k));
                wsum -= arr[wstart];
                wstart++;
            }
        }

        return result;
    }
    /*
     * Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.
     * */
    int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        int cursum = 0;
        int wstart = 0;
        for (auto i = 0; i < arr.size(); i++)
        {
            cursum += arr[i];
            if (i >= k - 1)
            {
                maxSum = max(cursum, maxSum);
                cursum -= arr[wstart];
                wstart++;

            }
        }

        return maxSum;
    }
};

int main() {
    vector<int> v{1, 3, 2, 6, -1, 4, 1, 8, 2};
    Solution solution;
//    vector<double> r = solution.AverageContSubArr(v, 5);
//    display_vect(r);

    vector<int> v1{2, 1, 5, 1, 3, 2};
    cout << solution.findMaxSumSubArray(3, v1) << "\n";
}
