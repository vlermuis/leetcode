/*
1436. Destination City (Easy)

https://leetcode.com/problems/destination-city/

Runtime: 20 ms, faster than 97.63% of C++ online submissions for Destination City.
Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Destination City.

Runtime: 116 ms, faster than 6.37% of C++ online submissions for Destination City.
Memory Usage: 32.9 MB, less than 100.00% of C++ online submissions for Destination City.
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> map_paths;
        map_paths.clear();
        for (auto x : paths)
        {
            map_paths[x[0]]++;
        }
        for (auto i = 0; i < paths.size(); i++)
        {
            string city = paths[i][1];
            if (map_paths[city] == 0)
            {
                return city;
            }
        }
        return "";
    }




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
    
    string _destCity(vector<vector<string>>& paths) {
        string city = paths[0][1];
        while(findSecondCity(paths, city) != "")
        {
            city = findSecondCity(paths, city);
        }
        return city;
    }
};