/* https://leetcode.com/problems/reverse-string/description/
 * Easy
 */


char* reverseString(char* s) {
    int len = strlen(s);
    int i = 0;
    for (i = 0; i < len/2; i++)
    {
       char temp = s[len-i-1];
       s[len-i-1] = s[i];
       s[i] = temp;
    }
return s;
}
