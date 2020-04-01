/*

https://www.hackerrank.com/challenges/cpp-lower-bound/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen


*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> qv;

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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int qtmp;
        cin >> qtmp;
        qv.push_back(qtmp);
    }
    for (int i = 0; i < q; i++)
    {
        std::vector<int>::iterator low;
        low = lower_bound(v.begin(), v.end(), qv[i]);
        if (v[low- v.begin()] == qv[i])
        {
            cout << "Yes " << (low- v.begin()) + 1 << endl;
        }
        else
        {
            cout << "No " << (low- v.begin() + 1) << endl;
        }

    }
        

    return 0;
}
