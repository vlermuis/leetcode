/*
https://leetcode.com/problems/merge-sorted-array/description/

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


void merge(int* nums1, int m, int* nums2, int n) {
    int j = 0;
    for (j = 0; j < n; j++)
    {
        nums1[m + j] = nums2[j];
    }
    quicksort(nums1, m + n);
}