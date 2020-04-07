/*
https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem?h_r=internal-search


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string, long int> adbook;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   map<string, long int> adbook;
   int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        long int number;
        cin >> number;
        adbook.insert(pair<string, long int>(name, number));
    }
    while(1)
    {
        string qname;
        cin >> qname;
        if (qname.empty())
        {
            break;
        }
    
        auto itrf = adbook.find(qname);
        if (itrf != adbook.end())
        {
            cout << itrf->first << "=" << itrf->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
