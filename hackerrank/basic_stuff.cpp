/*
https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

*/
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

void update(int *a,int *b) {
    // Complete this function    
    int sum = *a + *b;
    int dif = *a - *b;
    if (dif < 0)
    {
        dif *= -1;
    }
    *a = sum;
    *b = dif;
}



int main() {
	
	    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);


/********************************************/
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


struct Student
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    

    return 0;
}

#include <stdio.h>


