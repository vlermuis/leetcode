/*
* 350. Intersection of Two Arrays II (Easy)
* https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
*
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

void shift_array(int * a, int start_idx, int len)
{
    int i;
    for (i = start_idx; i < len -1; i++)
    {
        a[i] = a[i+1];
    }

}


bool isElementInSortArray(int* nums, int numsSize, int element)
{
    int start = 0;
    int end = numsSize - 1;
    int idx = (end + start)/2;
    while (start <= end)
    {
        if (nums[idx] < element)
        {
            start = idx + 1;
        }
        else if (nums[idx] == element)
            {
                shift_array(nums, idx, numsSize);
                return true;
            }
            else
            {
                end = idx -1;
            }
        idx = (end + start)/2;
    }
    return false;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    quicksort(nums1, nums1Size);
    quicksort(nums2, nums2Size);

    int numsB = 0;
    int numsS = 0;
    int* nums_s = NULL;
    int* nums_b = NULL;
    if (nums1Size > nums2Size)
    {
        numsB = nums1Size;
        nums_b = nums1;
        numsS = nums2Size;
        nums_s = nums2;
    }
    else
    {
        numsB = nums2Size;
        nums_b = nums2;
        numsS = nums1Size;
        nums_s = nums1;
    }
    int* rnums = (int*)malloc(sizeof(int)*numsS);
    int rnumsSize = 0;
    int i = 0;
    for (i = 0; i < numsS; i++)
    {
        if (isElementInSortArray(nums_b, numsB, nums_s[i]))
        {
            rnums[rnumsSize] = nums_s[i];
            rnumsSize++;
            numsB--;
        }
    }

    *returnSize = rnumsSize;
    return rnums;
}

