/*
https://leetcode.com/problems/contains-duplicate/description/
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


bool containsDuplicate(int* nums, int numsSize) {

    int i, j;
    quicksort(nums, numsSize);
    if (numsSize == 2)
    {
        if (nums[0] == nums[1])
        {
            return true;
        }
    }
    for (i = 1; i < numsSize-1; i++)
    {
        if ((nums[i] == nums[i-1]) || (nums[i] == nums[i+1]))
        {
            return true;
        }
    }
    return false;
}
