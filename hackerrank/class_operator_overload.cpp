/*
https://www.hackerrank.com/challenges/box-it/problem?h_r=next-challenge&h_v=zen

*/

#include<bits/stdc++.h>

using namespace std;
#include <iostream>

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    private:
    int lenght;
    int breadth;
    int height;

    public:
    Box();
    Box(int l, int b, int h);
    Box(Box& pbox);
    int getLength(); // Return box's length
    int getBreadth (); // Return box's breadth
    int getHeight ();  //Return box's height
    long long CalculateVolume();
    friend bool operator < ( Box&A,Box& B){
        if( (A.lenght < B.lenght) || ((A.breadth < B.breadth) && (A.lenght == B.lenght)) || ((A.height < B.height) && (A.lenght == B.lenght) && (A.breadth == B.breadth)) ){
            return true;
        }else{
            return false;
        }
    };
    
    friend ostream& operator<< (ostream& output, const Box& B){
        output << B.lenght << " " << B.breadth << " " << B.height;
        return output;
    }

};

Box::Box()
{
    lenght = 0;
    breadth = 0;
    height = 0;
}
Box::Box(int l, int b, int h)
{
    lenght = l;
    breadth = b;
    height = h;
}
Box::Box(Box& pbox)
{
    lenght = pbox.lenght;
    breadth = pbox.breadth;
    height = pbox.height;
}

int Box::getLength() // Return box's length
{
    return lenght;
}
int Box::getBreadth() // Return box's breadth
{
    return breadth;
}
int Box::getHeight()  //Return box's height
{
    return height;
}
long long Box::CalculateVolume()
{
    return (long long)lenght*breadth*height;
}
    


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}