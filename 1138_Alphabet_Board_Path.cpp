/*
1138. Alphabet Board Path (Medium)

https://leetcode.com/problems/alphabet-board-path/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Alphabet Board Path.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Alphabet Board Path.
*/

struct sLetter
{
    int pos_x;
    int pos_y;
    sLetter(int x, int y) : pos_x(x), pos_y(y){}
};


class Solution {
public:
    string moveUpDown(string current, int dx)
    {
        if (dx > 0)
        {
            for (auto i = 0; i < dx; i++)
            {
                current += "D";
            }
        }
        if (dx < 0)
        {
            dx *= -1;
            for (auto i = 0; i < dx; i++)
            {
                current += "U";
            }
        }
        return current;
    }
    string moveRightLeft(string current, int dy)
    {
        if (dy > 0)
        {
            for (auto i = 0; i < dy; i++)
            {
                current += "R";//"D";
            }
        }
        if (dy < 0)
        {
            dy *= -1;
            for (auto i = 0; i < dy; i++)
            {
                current += "L";//"U";
            }
        }
        return current;
    }

    string alphabetBoardPath(string target) {
        string result = "";
        vector<string> board{"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};

        vector<sLetter> alphabet;
        for (auto i = 0; i < board.size(); i++)
        {
            for (auto j = 0; j < board[i].length(); j++)
            {
                alphabet.push_back(sLetter(i,j));
            }
        }

        int cx = 0;
        int cy = 0;
        bool bIsFromZ = false;

        for (auto i = 0; i < target.length(); i++)
        {
            int lsc = (int)target[i] - 97;
            int nx = alphabet[lsc].pos_x;
            int ny = alphabet[lsc].pos_y;
           // cout << target[i] << ": " << nx << ": " << ny << "\n";
            int dx = nx - cx;
            int dy = ny - cy;
            if ((lsc != 25) && (!bIsFromZ))
            {
                if ((dx == 0) && (dy == 0))
                {
                    result += "!";
                } else
                {
                    result = moveUpDown(result, dx);
                    result = moveRightLeft(result, dy);
                    result += "!";
                }
            } else
            {
                if (lsc == 25)
                {
                    result = moveRightLeft(result, dy);
                    result = moveUpDown(result, dx);
                    result += "!";
                    bIsFromZ = true;
                } else
                {
                    result = moveUpDown(result, dx);
                    result = moveRightLeft(result, dy);
                    result += "!";
                    bIsFromZ = false;
                }
            }

            cx = nx;
            cy = ny;

        }

        return result;
    }

};
