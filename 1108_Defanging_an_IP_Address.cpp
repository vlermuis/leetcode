/*
1108. Defanging an IP Address (Easy)

https://leetcode.com/problems/defanging-an-ip-address/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defanging an IP Address.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Defanging an IP Address.
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string defangIPaddr(string address)
    {
        auto s = 0;
        auto f = address.find(".");
        string result = "";
        while ((f > 0) && (f < address.size()))
        {
            result +=  address.substr(s, f - s);
            result += "[.]";
            s = f + 1;
            f = address.find(".", f + 1);
        }
        result +=  address.substr(s, f - s);
        return result;
    }
};

string str0 = "127.0.0.1";

int main()
{
    Solution solution;
    cout << solution.defangIPaddr(str0);
    return 0;
}
