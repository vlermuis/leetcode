/*
https://www.hackerrank.com/challenges/vector-erase/problem?h_r=next-challenge&h_v=zen

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int pos;
    cin >> pos;
    int r1,r2;
    cin >> r1;
    cin >> r2;

    v.erase(v.begin()+pos-1);
    v.erase(v.begin()+r1-1, v.begin()+r2-1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
