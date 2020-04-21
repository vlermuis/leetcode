#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
/*
    vector<vector<int>> largestTriangleArea(vector<int>& points)
    {
    }
*/
    void printPowerSet(char *set, int set_size)
    {
        /*set_size of power set of a set with set_size
        n is (2**n -1)*/
        unsigned int pow_set_size = pow(2, set_size);
        int counter, j;

        /*Run from counter 000..0 to 111..1*/
        for(counter = 0; counter < pow_set_size; counter++)
        {
            for(j = 0; j < set_size; j++)
            {
                /* Check if jth bit in the counter is set
                    If set then print jth element from set */
                if(counter & (1 << j))
                    cout << set[j];
            }
        cout << endl;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        /*set_size of power set of a set with set_size
        n is (2**n -1)*/
        unsigned int pow_set_size = pow(2, nums.size());
        int counter, j;

        /*Run from counter 000..0 to 111..1*/
        for(counter = 0; counter < pow_set_size; counter++)
        {
            vector<int> current;
            int csum = 0;
            for(j = 0; j < nums.size(); j++)
            {
                /* Check if jth bit in the counter is set
                    If set then print jth element from set */
                if(counter & (1 << j))
                {
                    csum += nums[j];
                    current.push_back(nums[j]);
                }
            }
            if ((csum == 0) && (current.size() == 3))
            {
                sort(current.begin(),current.end());
                auto f = find(result.begin(), result.end(),current);
                if (f == result.end())
                {
                    result.push_back(current);
                }
            }
        }
        return result;
    }

};

int main()
{
    vector<int> p{1,2,3,4};
    char str0[] = "abc";
    int data[] = {1, 2, 3};
    vector<int> v{-1, 0, 1, 2, -1, -4};
    vector<int> v1{0,-5,3,-4,1,3,-4,-2,-2,-2,0,3,0,1,-4,-2,0};
    Solution solution;
    vector<vector<int>> r = solution.threeSum(v1);

    for (auto itr = r.begin(); itr != r.end(); itr++)
    {
        vector<int> tmp = *itr;
        for (auto el = tmp.begin(); el != tmp.end(); el++)
        {
            cout << *el << ", ";
        }
        cout << endl;
    }

    return 0;
}
