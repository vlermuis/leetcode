/*
* 342. Power of Four (Easy)
* https://leetcode.com/problems/power-of-four/description/
* 
*/

bool tempFunc(int n)
{
    if ((n % 4) != 0)
    {
        return false;
    }
    else if ((n / 4) == 1)
        {
            return true;
        }
        else
        {
            return tempFunc(n / 4);
        }
    return false;

}

bool isPowerOfFour(int num)
{
    if (num < 4)
    {
        if (num == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return tempFunc(num);
}

