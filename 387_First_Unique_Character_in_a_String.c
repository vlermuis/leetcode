/*
https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1


*/
bool is_anoter_one_in(char* s, int size, char c, int idx)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((c == s[i]) && (i != idx))
        {
            return true;
        }
    }
    return false;
}

int firstUniqChar(char* s) {
    int s_len = strlen(s);
    int i;
    for (i = 0; i < s_len; i++)
    {
        if (!is_anoter_one_in(s, s_len, s[i], i))
        {
            return i;
        }
    }
    return -1;
   
}