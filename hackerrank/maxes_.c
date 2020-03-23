#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int i,j;
  int max_and = 0;
  int max_or = 0;
  int max_xor = 0;
  for (i = 1; i <= n; i++)
  {
      for (j = i+1; j <= n; j++)
      {
        int c_and = i&j;
        int c_or  = i|j;
        int c_xor = i^j;
         if ((c_and > max_and) && (c_and < k))
         {
             max_and = c_and;
         }
         if ((c_or > max_or) && (c_or < k))
         {
             max_or = c_or;
         }
         if ((c_xor > max_xor) && (c_xor < k))
         {
             max_xor = c_xor;
         }

      }
  }
  printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
