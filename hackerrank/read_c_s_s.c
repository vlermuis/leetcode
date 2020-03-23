#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 255
int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[MAX_LEN];
    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch);

    scanf("%s", s);
    printf("%s\n", s);

    scanf(" %[^\n]%*c", s);
    printf("%s\n",s);

    return 0;
}
