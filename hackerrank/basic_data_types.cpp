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


    return 0;
}
