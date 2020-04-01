/*
https://www.hackerrank.com/challenges/cpp-sets/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
sets_stl

Sets STL
 ....
 

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int nquery;
        cin >> nquery;
        int nnum;
        cin >> nnum;
        switch (nquery) 
        {
            case 1:
                s.insert(nnum);
            break;
            case 2:
                s.erase(nnum);
            break;
            case 3:
                set<int>::iterator itr = s.find(nnum);
                if (itr != s.end())
                {
                    cout << "Yes" << endl;
                }                    
                else {
                    cout << "No" << endl;
                }
            break;
        }
    }  

    return 0;
}



