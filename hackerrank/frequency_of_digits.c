#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int result[10] = {0};
    char str[1000] = {0};
    scanf("%s", &str);
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++)
    {
        switch(str[i])
        {
        case '0':
            result[0]++;
            break;
        case '1':
            result[1]++;
            break;
        case '2':
            result[2]++;
            break;
        case '3':
            result[3]++;
            break;
        case '4':
            result[4]++;
            break;
        case '5':
            result[5]++;
            break;
        case '6':
            result[6]++;
            break;
        case '7':
            result[7]++;
            break;
        case '8':
            result[8]++;
            break;
        case '9':
            result[9]++;
            break;

        default:
            break;
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");

    return 0;
}
