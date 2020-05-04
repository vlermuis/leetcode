/*
1431. Kids With the Greatest Number of Candies (Easy)

https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
Runtime: 4 ms, faster than 90.73% of C++ online submissions for Kids With the Greatest Number of Candies.
Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Kids With the Greatest Number of Candies.
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max = candies[0];
        for (auto i = 0; i < candies.size(); i++)
        {
            if (max < candies[i])
            {
                max = candies[i];
            }
        }
        for (auto i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                result.push_back(true);
            } else
            {
                result.push_back(false);
            }
        }
        return result;
        
    }
};