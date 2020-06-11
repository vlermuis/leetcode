/*
1423. Maximum Points You Can Obtain from Cards (Medium)

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Runtime: 204 ms, faster than 34.50% of C++ online submissions for Maximum Points You Can Obtain from Cards.
Memory Usage: 42.5 MB, less than 81.02% of C++ online submissions for Maximum Points You Can Obtain from Cards.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result;
        // calculate initial sum of sliding window: sum of all k elements from end
        int sum = 0;
        int cplen = cardPoints.size();
        for (auto i = 0; i < k; i++)
        {
            sum += cardPoints[cplen - 1 - i];
        }
        result = sum;
        // use sliding window approach
        for (auto i = 0; i < k; i++)
        {
            sum -= cardPoints[cplen - k + i];
            sum += cardPoints[i];
             if (sum > result)
             {
                 result = sum;
             }
        }
        return result;
    }
};
int main() {
    vector<int> v{1,2,3,4,5,6,1};
    vector<int> v1{2,2,2};
    vector<int> v2{9,7,7,9,7,7,9};
    vector<int> v3{1,1000,1};
    vector<int> v4{1,79,80,1,1,1,200,1};
    Solution solution;
    int r;
    r = solution.maxScore(v, 3);
    cout << r << "\n";
    r = solution.maxScore(v1, 2);
    cout << r << "\n";
    r = solution.maxScore(v2, 7);
    cout << r << "\n";
    r = solution.maxScore(v3, 1);
    cout << r << "\n";
    r = solution.maxScore(v4, 3);
    cout << r << "\n";

    return 0;
}
