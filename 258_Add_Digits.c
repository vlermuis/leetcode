/*
https://leetcode.com/problems/add-digits/description/
https://leetcode.com/submissions/detail/153117223/
*/
int sumfig(int n)
{
    int sum = 0;
    while (n > 9)
    {
        sum += (n % 10);
        n /= 10;
    }
    sum += n;
    return sum;
}

int addDigits(int num) {

    int result  = sumfig(num);
    while(result > 9)
    {
        result  = sumfig(result);
    }
    return result;
}
