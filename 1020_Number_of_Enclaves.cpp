/*
1020. Number of Enclaves (Medium)

flooding

https://leetcode.com/problems/number-of-enclaves/
Runtime: 132 ms, faster than 15.22% of C++ online submissions for Number of Enclaves.
Memory Usage: 22 MB, less than 6.25% of C++ online submissions for Number of Enclaves.
*/

class Solution {
public:
    void flood(vector<vector<int>>& A, int x, int y)
    {
        if (A[x][y] == 0)
        {
            return;
        }
        A[x][y] = 0;
        if (x > 0)
        {
            flood(A, x - 1, y);
        }
        if (x < A.size() - 1)
        {
            flood(A, x + 1, y);
        }
        if (y > 0)
        {
            flood(A, x, y -1);
        }
        if (y < A[0].size() - 1)
        {
            flood(A, x, y + 1);
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        int result = 0;
        for (auto i = 0; i < A[0].size(); i++)
        {
            flood(A, 0, i);
        }
        for (auto i = 0; i < A[0].size(); i++)
        {
            flood(A, A.size()-1, i);
        }
        for (auto i = 0; i < A.size(); i++)
        {
            flood(A, i, 0);
        }
        for (auto i = 0; i < A.size(); i++)
        {
            flood(A, i, A[0].size()-1);
        }

        for (auto i = 0; i < A.size(); i++)
        {
            for (auto j = 0; j < A[0].size(); j++)
            {
                result += A[i][j];
            }
        }

        return result;
    }
};