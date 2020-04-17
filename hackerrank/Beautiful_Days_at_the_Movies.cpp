/*
https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
Beautiful Days at the Movies

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulDays function below.
long int fracten(int n)
{
    long int r = 1;
    for (auto i = 0; i < n; i++)
    {
        r *= 10;
    }
    return r;
}


int beautifulDays(int i, int j, int k) {
    int pos;
    int reverse_num;
    vector<int> digits;
    int bdays = 0;
    for (auto itr = i; itr <= j; itr++)
    {
        int n = itr;
        digits.clear();
        while (n > 0)
        {
            int fr = n % 10;
            n /= 10;
            digits.push_back(fr);
        }
        reverse_num = 0;
        pos = 0;
        int ds = digits.size();
        for (auto i = ds-1; i >= 0; i--)
        {
            reverse_num += (digits[i] * fracten(pos));
            pos++;
        }
       if ((abs(itr - reverse_num) % k) == 0)
        {
            bdays++;
        }

    }
    return bdays;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
