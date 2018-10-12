/*
https://leetcode.com/problems/number-of-1-bits/description/
https://leetcode.com/submissions/detail/153111541/

*/
int hammingWeight(uint32_t n) {
  int r = 0;
  int i = 0;
  for (i = 0; i < 32; i++)
  {
     uint32_t mask = 1 << i;
     if (n & mask)
     {
        r++;
     }
  }
  return r;
}