/*
717. 1-bit and 2-bit Characters (Easy)

https://leetcode.com/problems/1-bit-and-2-bit-characters/
Runtime: 8 ms, faster than 15.09% of C++ online submissions for 1-bit and 2-bit Characters.
Memory Usage: 9.9 MB, less than 66.67% of C++ online submissions for 1-bit and 2-bit Characters.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool bIsCurOneBit = false;
        int i;
        for (i = 0; i < bits.size(); i++)
        {
            if (bits[i] == 1)
            {
                bIsCurOneBit = false;
                i++;
            } else
            {
                bIsCurOneBit = true;
            }
        }
        return bIsCurOneBit;
    }
};

int main()
{
    vector<int> v{1, 0, 0};
    vector<int> v1{1, 1, 1, 0};

    Solution solution;
    cout << solution.isOneBitCharacter(v) << "\n";
    cout << solution.isOneBitCharacter(v1) << "\n";

    return 0;
}
