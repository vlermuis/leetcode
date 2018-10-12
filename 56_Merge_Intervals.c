/*


https://leetcode.com/problems/merge-intervals/description/
https://leetcode.com/submissions/detail/153705826/
*/
 typedef struct {
      int start;
      int end;
  }Interval;

void quicksort(Interval *A, int len);

void quicksort(Interval *A, int len) {
  if (len < 2) return;

  Interval pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i].start < pivot.start) i++;
    while (A[j].start > pivot.start) j--;

    if (i >= j) break;

    Interval temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    *returnSize = 0;
    if (intervalsSize == 0)
    {
        return NULL;
    }
    quicksort(intervals, intervalsSize);
    Interval* output_intervals = (Interval*)malloc(sizeof(Interval)*intervalsSize);
    int i = 0;
    output_intervals[*returnSize].start = intervals[0].start;
    output_intervals[*returnSize].end = intervals[0].end;
    for (i = 1; i < intervalsSize; i++)
    {
        if (intervals[i].start <= output_intervals[*returnSize].end )
        {
            if (intervals[i].end > output_intervals[*returnSize].end)
            {
                output_intervals[*returnSize].end = intervals[i].end;
            }
        }
        else
        {
            (*returnSize)++;
            output_intervals[*returnSize].start = intervals[i].start;
            output_intervals[*returnSize].end = intervals[i].end;
        }
    }
        (*returnSize)++;
    return output_intervals;
}