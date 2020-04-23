/*


*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
O(n^3)
*/
int subMaxSum0(int* array, int n)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += array[k];
            }
            best = max(best,sum);
        }
    }
    cout << best << "\n";
    return best;
}
/*
O(n^2)
*/
int subMaxSum1(int* array, int n)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        int sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += array[b];
            best = max(best,sum);
        }
    }
    cout << best << "\n";
    return best;
}

/*
O(n)
*/
int subMaxSum(int* array, int n)
{
    int best = 0;
    int sum = 0;
    for (int a = 0; a < n; a++)
    {
        sum = max(array[a], array[a] + sum);
        best = max(best,sum);
    }
    cout << best << "\n";
    return best;
}

int data[] = {-1, 2, 4, -3, 5, 2, -5, 2};

int main()
{
    subMaxSum(data, 8);
    return 0;
}
