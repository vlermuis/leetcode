/*
1436. Destination City (Easy)

https://leetcode.com/problems/destination-city/
Runtime: 116 ms, faster than 6.37% of C++ online submissions for Destination City.
Memory Usage: 32.9 MB, less than 100.00% of C++ online submissions for Destination City.
*/

class Solution {
public:
    string findSecondCity(vector<vector<string>>& paths, string firstCity)
    {
        for (auto x : paths)
        {
            if (x[0] == firstCity)
            {
                return x[1];
            }
        }
        return "";
    }
    
    string destCity(vector<vector<string>>& paths) {
        string city = paths[0][1];
        while(findSecondCity(paths, city) != "")
        {
            city = findSecondCity(paths, city);
        }
        return city;
    }
};