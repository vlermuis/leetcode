/*
1281. Subtract the Product and Sum of Digits of an Integer (Easy)

https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
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
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;
        while(n > 0)
        {
            int r = n % 10;
            prod *= r;
            sum += r;
            n /= 10;
        }
        return (prod - sum);
    }
};




int main()
{
    Solution solution;
    cout << solution.subtractProductAndSum(234) << "\n";
    cout << solution.subtractProductAndSum(4421) << "\n";
 return 0;
}


