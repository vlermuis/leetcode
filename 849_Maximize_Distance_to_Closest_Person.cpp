/*
849. Maximize Distance to Closest Person (Easy)
https://leetcode.com/problems/maximize-distance-to-closest-person/
Runtime: 12 ms, faster than 86.84% of C++ online submissions for Maximize Distance to Closest Person.
Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Maximize Distance to Closest Person.
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        bool bIsFirstSeq = true;
        int first_corner_seq = 0;
        int last_corner_seq = 0;
        int max_middle_seq = 0;
        int seq;
        for (auto itr = seats.begin(); itr != seats.end(); itr++)
        {
            if (*itr == 0)
            {
                int s = 0;
                vector<int>::iterator i;
                for (i = itr; i != seats.end(); i++)
                {
                    s += *i;
                    if (s > 0)
                    {
                        break;
                    }
                }
                seq = distance(itr, i);
                if (max_middle_seq < seq)
                {
                    max_middle_seq = seq;
                }
                if (bIsFirstSeq)
                {
                    first_corner_seq = seq;
                    bIsFirstSeq = false;
                }
                last_corner_seq = seq;
                itr += (seq-1);
            }
        }
        int frseq = max_middle_seq % 2;
        if (frseq)
        {
            max_middle_seq = (max_middle_seq / 2) + 1;
        }
        else
        {
            max_middle_seq /=2;
        }
        if (seats.front() != 0)
        {
            first_corner_seq = 0;
        }
        if (seats.back() != 0)
        {
            last_corner_seq = 0;
        }
        vector<int> r{max_middle_seq, first_corner_seq, last_corner_seq};
        sort(r.begin(), r.end());
        return r.back();
    }
};