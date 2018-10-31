/*
* 41. First Missing Positive (Hard)
* https://leetcode.com/problems/first-missing-positive/description/
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

int firstMissingPositive(int* nums, int numsSize) {
    int i;
    quicksort(nums, numsSize);
    int element = 1;
    for (i = 0; i < numsSize; i++)
    {
          if (nums[i] > 0)
          {
              if ((i > 0) && (nums[i-1] == nums[i]))
              {
                  continue;
              }
                if (nums[i] != element)
                {
                    return element;
                }
                else
                {
                    element++;
                }
          }
    }
    return element;
}
