/*
https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

*/
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    // Complete the code.
    int i;
    long l;
    char c;
    float f;
    double d;

    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
    cout<<i<<"\n"<<l<<"\n"<<c<<"\n";
    cout<<fixed<<setprecision(3)<<f<<"\n";
    cout<<fixed<<setprecision(9)<<d<<"\n";
/**********************************************************/


    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n-1; i >=0; i--)
    {
        cout << arr[i] << " ";
    }


/*********************************************************/
string numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if ((n >= 1) && (n <= 9))
    {
        cout << numbers[n-1] << endl;
    }
    else {
    cout << "Greater than 9" << endl;
    }

/***********************************************************/

     int a;
     int b;
     cin >> a;
     cin >> b;
     for (int i = a; i <= b; i++)
     {
        if ((i >= 1) && (i <= 9))
        {
            cout << numbers[i-1] << endl;
        }
        else
        {
            if ((i % 2))
            {
                cout << "odd" << endl;
            }            
            else 
            {
                cout << "even" << endl;
            }
        }
     }

    return 0;
}
