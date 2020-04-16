/*
9. Palindrome Number (Easy)
https://leetcode.com/problems/palindrome-number/

Runtime: 36 ms, faster than 6.14% of C++ online submissions for Palindrome Number.
Memory Usage: 9.5 MB, less than 15.45% of C++ online submissions for Palindrome Number.
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> backw;
        if (x <= 0)
        {
            if (x == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        while(x > 0)
        {
            backw.push_back(x % 10);
            x /= 10;
        }
        for (auto itrs = backw.begin(), itre = backw.end()-1; itrs <= itre; itrs++, itre--)
        {
            if (*itrs != *itre)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome(1) << endl;
    return 0;
}

