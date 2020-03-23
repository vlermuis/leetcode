/*
https://leetcode.com/problems/find-the-difference/
389. Find the Difference (Easy)
Runtime: 0 ms, faster than 100.00% of C online submissions for Find the Difference.
Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Find the Difference.
*/
void quicksort(char *A, int len);

void quicksort(char *A, int len) {
  if (len < 2) return;

  char pivot = A[len / 2];

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

char findTheDifference(char * s, char * t){
    int s_len = strlen(s);
    int i = 0;
    if (s_len == 0)
    {
        return t[0];
    }
    
    quicksort(s, s_len);
    quicksort(t, s_len+1);
    for (i = 0; i < s_len; i++)
    {
        if (s[i] != t[i])
        {
            return t[i];
        }
        if ((i == (s_len - 1)) && (s[i] == t[i]))
        {
            return t[i+1];
        }

    }

 return ' ';
}

