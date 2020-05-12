/*
1299. Replace Elements with Greatest Element on Right Side (Easy)

https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
Runtime: 28 ms, faster than 95.96% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
Memory Usage: 15 MB, less than 100.00% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = arr.back();
        int arr_size = arr.size();
        int idx = arr_size - 1;
        for (auto i = 0; i != arr_size; i++)
        {
            int temp  = arr[idx];
            arr[idx] = max;
            if (max < temp)
            {
                max = temp;
            }
            idx--;
        }
        arr.back() = -1;
        return arr;
    }
};