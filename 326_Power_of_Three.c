/* https://leetcode.com/problems/power-of-three/description/
 *  Easy
 */

bool tempFunc(int n)
{
    if ((n % 3) != 0)
    {
        return false;
    }
    else if ((n / 3) == 1)
        {
            return true;
        }
        else
        {
            return tempFunc(n / 3);
        }
    return false;

}

bool isPowerOfThree(int n) {
    if (n < 3)
    {
        if (n == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return tempFunc(n);
}

