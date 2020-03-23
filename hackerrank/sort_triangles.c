#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
int get_square(triangle* tr)
{
    int p = (tr->a + tr->b + tr->c)/2;
    return sqrt(p*(p-tr->a)*(p-tr->b)*(p-tr->c));
}
void quicksort_triangles(triangle* A, int len);

void quicksort_triangles(triangle* A, int len)
{
      if (len < 2) return;

  int pivot = get_square(&A[len / 2]);

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (get_square(&A[i]) < pivot) i++;
    while (get_square(&A[j]) > pivot) j--;

    if (i >= j) break;

    triangle temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort_triangles(A, i);
  quicksort_triangles(A + i, len - i);

}


void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int i;
    quicksort_triangles(tr, n);
    
}

int main()