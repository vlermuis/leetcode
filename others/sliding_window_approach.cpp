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
};

int main() {
    vector<int> v{1, 3, 2, 6, -1, 4, 1, 8, 2};
    Solution solution;
    vector<double> r = solution.AverageContSubArr(v, 5);
    display_vect(r);
}
