/*
https://www.hackerrank.com/challenges/find-digits/problem?h_r=internal-search

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    vector<int> v;
    int cn = n;
    int result = 0;
    while(cn > 0)
    {
        v.push_back(cn % 10);
        cn /= 10;
    }
    for (auto i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            if ((n % v[i]) == 0)
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
