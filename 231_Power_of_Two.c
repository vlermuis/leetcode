/*
https://leetcode.com/problems/power-of-two/description/

https://leetcode.com/submissions/detail/153126851/
*/
bool isPowerOfTwo(int n) {
  if (n == 0)
  {
     return false;
  }
  else
  {
    while(n != 1)
    {
        if (n % 2)
        {
          return false;
        }
        n = n >> 1;
    }
    return true;
  }

}