/*
https://leetcode.com/problems/first-bad-version/
 (Easy)
*/

typedef int bool;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

bool isBadVersion(int version)
{
    if (version >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


int firstBadVersion(int n) 
{
    int i;
    if (n == 1)
    {
        return 1;
    }
    for (i = n; i >= 0; i--)
    {
        if (!isBadVersion(i))
        {
            return i+1;
        }
    }
    return 0;
}

int main()
{
    printf(" %d \n", firstBadVersion(2));
    return 0;
}
