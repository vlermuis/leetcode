#include <stdio.h>
#include <stdlib.h>

/*
https://www.quora.com/Which-sorting-algorithm-is-best-and-why



There is no ideal sorting algorithm for every single case. The best algorithm to use varies from case to case. Consider the 3 most common  O(nlogn) comparison sorts.

Merge Sort

Split your array in half. Recursively merge sort the left and right sub-arrays. Then, merge them together (linear time) to get the full sorted array.

Pros:

Has  O(n log n)  worst-case run time.
Of the 3 algorithms here, it is the only one that is stable, so if you want to retain the ordering of comparatively equivalent items, this should be your go-to.
Easy to implement on linked list data structures. Does not require random access.
Cons:

Has  O(n)  space complexity, which is worse than the other 2 sorts.
Slower than the other 2 algorithms in practice. Why? You have to write all your data into another array and back into your original one. Copying is usually slower than comparing.


Heap Sort

Generate a heap data structure on the array. Then, pop the top of the heap and move it to the end of the array. Repeat until the heap is empty and the entire array is sorted.

Pros:

Has  O(nlogn)  worst-case run time.
Can sort in-place so uses  O(1)  additional space.
Cons:

Unstable!
Still much slower than Quick Sort on average. You still need to perform a swap on every element in the array, even if it’s already in the right place.


Quick Sort

Pick a pivot from the array and partition the array into sub-arrays. Everything in the left sub-array is less than the pivot. 
Everything in the right sub-array is greater than the pivot. Recursively sort the left and right sub-arrays.

Pros:

Generally the fastest sorting algorithm in practice. It only swaps what needs to be swapped. Swaps are slow!
Can be performed in-place, but in practice, the stack frames from recursive function calls results in  O(log n)  space complexity.
Cons:

Has  O(n2)  in the worst case. Ideally, the chosen pivot is the median. The further away it is from the median, the worse the performance.
Like Heap Sort, it’s unstable!
Which one’s the best?

As you can see, each of the sorting algorithms have their pros and cons. Choose the sort that is best suited for your data. 
If you’re constrained in space, go for heap sort. If you need something stable, merge sort is your friend. For nearly sorted data, consider that insertion sort is  O(n)  time!

Modern sorting algorithms use hybrid sorts that combine the best qualities of the different basic sorting algorithms. 
Perhaps the most widely used (and arguably the “best”) is introsort (std::sort in C++) which runs quick sort and switches to heap sort when the recursion gets too deep. 
This way, you get the fast performance of quick sort in practice while guaranteeing a worst case  O(n log n)  run time.
*/


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
