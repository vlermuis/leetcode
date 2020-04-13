/*

852. Peak Index in a Mountain Array (Easy)
https://leetcode.com/problems/peak-index-in-a-mountain-array/
Runtime: 16 ms, faster than 53.34% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Peak Index in a Mountain Array.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = A.front();
        int pos = 0;
        for (auto itr = A.begin(); itr != A.end(); itr++)
        {
            if (max < *itr)
            {
                max = *itr;
                pos = distance(A.begin(), itr);
            }
        }
        return pos;
    }
};