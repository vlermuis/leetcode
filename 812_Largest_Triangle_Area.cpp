/*
812. Largest Triangle Area (Easy)

https://leetcode.com/problems/largest-triangle-area/
Runtime: 36 ms, faster than 40.44% of C++ online submissions for Largest Triangle Area.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Largest Triangle Area.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        double area = abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)));
        area /= 2;
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points)
    {
        double max_area = 0;
        for (auto i = 0; i < points.size(); i++)
        {
            for (auto j = 0; j < points.size(); j++)
            {
                for (auto k = 0; k < points.size(); k++)
                {
                    if ((i != j) && (i != k) && (j!= k))
                    {
                        double cur_area = triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                        if (max_area < cur_area)
                        {
                            max_area = cur_area;
                        }
                    }
                }

            }

        }
        return max_area;
    }
};

int main()
{
    vector<vector<int>> p{{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    vector<vector<int>> p1{{1,0}, {0,0}, {0,1}};
    Solution solution;
//    cout << solution.triangleArea(p[0][0], p[0][1], p[3][0], p[3][1], p[4][0], p[4][1]) << endl;
//    cout << p.size() << endl;
    cout << solution.largestTriangleArea(p) << endl;
    cout << solution.largestTriangleArea(p1) << endl;

    return 0;
}
