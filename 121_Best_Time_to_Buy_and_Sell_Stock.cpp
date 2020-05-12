/*
121. Best Time to Buy and Sell Stock (Easy)

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Runtime: 16 ms, faster than 12.17% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 13.1 MB, less than 5.51% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min = INT32_MAX;

        for (auto i = 0; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
            }
            if (result < (prices[i] - min))
            {
                result = prices[i] - min;
            }
        }
        return result;
        
    }
};