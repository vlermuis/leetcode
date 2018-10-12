/*
https://leetcode.com/problems/missing-number/description/
easy 
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

int missingNumber(int* nums, int numsSize) {
    quicksort(nums, numsSize);
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
return numsSize;          
}