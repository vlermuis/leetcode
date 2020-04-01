/*
https://www.hackerrank.com/challenges/cpp-maps/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

Maps-STL

*/

#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> maps;

map<string, int>::iterator itr;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int query;
        cin >> query;
        switch (query) 
        {
        case 1:
            {
                string name;
                cin >> name;
                int mark;
                cin >> mark;
                itr = maps.find(name);
                if (itr != maps.end())
                {
                    maps[name] = maps[name] + mark;
                }
                else 
                {
                    maps.insert(make_pair(name, mark));
                }
            break;
            }
        case 2:
            {
                string name;
                cin >> name;
                maps.erase(name);
                break;
            }
        case 3:
            {
                string name;
                cin >> name;
                itr = maps.find(name);
                if (itr != maps.end())
                {
                    cout << maps[name] << endl;
                }
                else 
                {
                    cout << "0" << endl;
                }

                break;
            }
        }
    }
    return 0;
}



