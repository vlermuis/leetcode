/*
https://www.interviewbit.com/problems/add-one-to-number/

*/

vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> temp;
    bool bnext = false;
    auto itrl = A.end()-1;
    int rl = *itrl + 1;
    if (rl > 9)
    {
        rl -= 10;
        bnext = true;
    }
    temp.push_back(rl);
    for (auto itr = A.end()-2; itr >= A.begin(); itr--)
    {
        int r = *itr;
        if (bnext)
        {
            r++;
            bnext = false;
        }
        if (r > 9)
        {
            r -= 10;
            bnext = true;
        }
        temp.push_back(r);
   }
   if (bnext)
   {
       temp.push_back(1);
   }

    reverse(temp.begin(), temp.end());
    auto itr2 = temp.begin();
    while(*itr2 == 0)
    {
        temp.erase(temp.begin());
        itr2 = temp.begin();
    }
    

    return temp;

}