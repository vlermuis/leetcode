#include <stdio.h>
#include <stdlib.h>


/*
The time complexity of Quicksort is O(n log n) in the best case,
  O(n log n) in the average case, and O(n^2) in the worst case.
But because it has the best performance in the average case for most inputs,
Quicksort is generally considered the “fastest” sorting algorithm.
*/
void quicksort(int *A, int len);
void quicksort(int *A, int len) {
  if (len < 2) return;

  int pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;

    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}

/* bubble sort -hmm probably the slowest */
void bubblesort(int * nums, int numsSize)
{
    int bIsNotEnough = 1;
    int i, j;

    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < numsSize - 1; j++)
        {
            if (nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                bIsNotEnough = 1;
            }
        }
    }
}


/* merge sort */


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/*_______________________________________________*/

#define ARR_SIZE    (4096)//(65535)
int dat0[ARR_SIZE];
int main()
{
    int i;
    for (i = 0; i < ARR_SIZE; i++)
    {
        dat0[i] = rand();
    }
    quicksort(dat0, ARR_SIZE);
    //bubblesort(dat0, ARR_SIZE);
    //mergeSort(dat0, 0, ARR_SIZE-1);
    return 0;
}
