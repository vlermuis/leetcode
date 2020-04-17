#include <stdio.h>
#include <stdlib.h>

/*determine whether a point D lies inside triangle ABC
If D is inside of the triangle ABC

          A


         D
  C            B


ABCSquare = Square(A, B, C);
ABDSquare = Square(A, B, D);
BCDSquare = Square(B, C, D);
CADSquare = Square(C, A, D);
Sum = ABDSqare + BCDSquare + CADSquare;

if (ABCSquare < Sum)
     print("Outside");
else
     print("Inside");


Square  = ( x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2))/2


*/
float square(int x1, int y1, int x2, int y2, int x3, int y3)
{
    float square = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2;
    if (square < 0)
    {
        square *= -1;
    }
    return square;
}
/*
 triangle ABC with coordinates A(x1,y1), B(x2,y2), C(x3,y3)
 check if D(x,y) is inside ABC or not

 return 1 if inside and 0 otherwise

*/
int checkPointInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    float squareABD = square(x1, y1, x2, y2, x, y);
    float squareBCD = square(x2, y2, x3, y3, x, y);
    float squareCAD = square(x3, y3, x1, y1, x, y);

    float squareABC = square(x1, y1, x2, y2, x3, y3);

    if (squareABC < (squareABD + squareBCD + squareCAD))
    {
        return 0;//outside
    }
    else
    {
        return 1;//inside
    }
}
int main()
{
    printf("%d\n", checkPointInsideTriangle(150, 150, 250, 50, 50, 50, 150, 100));
    printf("%d\n", checkPointInsideTriangle(0, 0, 20, 0, 10, 30, 10, 15));

    return 0;
}
