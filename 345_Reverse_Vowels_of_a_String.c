/*
* 345. Reverse Vowels of a String (Easy)
* https://leetcode.com/problems/reverse-vowels-of-a-string/description/
* 
*/
char vowels[] = "aeiouAEIOU";
bool IsItVowel(char c)
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (c == vowels[i])
        {
            return true;
        }
    }
    return false;
}

int findVowelFromRight(char* s, int start_idx, int end_idx)
{
    int i = 0;
    for (i = start_idx; i < end_idx; i++)
    {
        if (IsItVowel(s[i]))
        {
            return i;
        }
    }
    return -1;
}
int findVowelFromLeft(char* s, int start_idx, int end_idx)
{
    int i = 0;
    for (i = start_idx; i > end_idx; i--)
    {
        if (IsItVowel(s[i]))
        {
            return i;
        }
    }
    return -1;
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    int i = 0;
    int right_idx = 0;
    int left_idx = len;
    while (right_idx < left_idx)
    {
        int ridx = findVowelFromRight(s, right_idx, left_idx);
        int lidx = findVowelFromLeft(s, left_idx, right_idx);
        if ((ridx != -1) && (lidx != -1))
        {
            char temp = s[ridx];
            s[ridx] = s[lidx];
            s[lidx] = temp;
            right_idx = ridx + 1;
            left_idx = lidx - 1;
        }
        else
        {
            break;
        }
    }
return s;
}

