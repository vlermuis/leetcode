#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Write function in C to add the digits of an integer
*/
long addNumsInInt(int num)
{
    long result = 0;
    while(num > 0)
    {
        result += num % 10;
        num /= 10;
    }

    return result;
}

/*
Write a function in C to find the difference between the maximum and minimum values in an array
*/

int findDiffBetweenMaxAndMin(int* nums, int numsSize)
{
    int i;
    int max = nums[0];
    int min = nums[0];

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    return (max - min);
}
/*
 count how many bits 1 in the number
*/
int countOneBits(int num)
{
    int result = 0;
    int mask;
    int i;
    for (i = 0; i < 32; i++)
    {
        mask = 1 << i;
        if (num & mask)
        {
            result++;
        }
    }
    return result;
}
int countOneBits2(int num)
{
    int result = 0;
    while(num > 0)
    {
        if (1 & num)
        {
            result++;
        }
        num = num >> 1;
    }
    return result;
}



int binarySearch(int* nums, int numsSize, int val)
{
    int idx = -1;
    int right = numsSize-1;
    int left = 0;
    while(1)
    {
        idx = ((right - left)/2) + left;
        if (nums[idx] == val)
        {
            return idx;
        }
        else
        {
            if (val < nums[idx] )
            {
                right = idx - 1;
            }
            else
            {
                left = idx + 1;
            }
        }
        if (right < left)
        {
            break;
        }
    }
    return -1;
}
void swapPointers2(int** p1, int** p2)
{
    int* ptemp = *p2;
    *p2 = *p1;
    *p1 = ptemp;
}



int findMaxDiff(int* nums, int numsSize)
{
    int min = nums[0];
    int max_diff = nums[1] - nums[0];
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] - min) > max_diff)
        {
            max_diff = nums[i] - min;
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    return max_diff;

}
/* List functoins */


 struct ListNode {
    int val;
    struct ListNode *next;
 };

typedef struct ListNode listnode;


void display_list(listnode* plist)
{
    while(plist != NULL)
    {
        printf("%d, ", plist->val);
        plist = plist->next;
    }
}

void clean_list(listnode* plist)
{
    listnode* ptmp = NULL;
    while(plist != NULL)
    {
        ptmp = plist->next;
        free(plist);
        plist = ptmp;
    }
}


void add_to_list(int data, listnode** pHead)
{
    if ((*pHead) == NULL)
    {
        listnode* pNode = (listnode*)malloc(sizeof(listnode));
        pNode->val = data;
        pNode->next = NULL;
        (*pHead) = pNode;
        return;
    }
    else
    {
        listnode* pCurrent = *pHead;
        while(pCurrent->next != NULL)
        {
            pCurrent = pCurrent->next;
        }
        listnode* pNode = (listnode*)malloc(sizeof(listnode));
        pNode->val = data;
        pNode->next = NULL;
        pCurrent->next = pNode;
    }

}

void array_to_list(int * nums, int data_size, listnode** pHead)
{
    int i;
    for (i = 0; i < data_size; i++)
    {
        add_to_list(nums[i], pHead);
    }

}


void display_n_from_tail(listnode* head, int n)
{
    listnode* prev = head;
    int idx = 0;
    while(head != NULL)
    {
        head = head->next;
        idx++;
        if (idx == 3)
        {
            break;
        }
    }
    while(head != NULL)
    {
        head = head->next;
        prev = prev->next;
    }
    printf("%d\n", prev->val);
}


/********************************************/

char* convertDecToHex(int num)
{
    char rev_hex[32] = {0};
    char result[32] = {0};
    int digits = 0;
    int cnum = num;
    int i;
    while (cnum > 0)
    {
        int fr = cnum % 16;
        if (fr < 9)
        {
            sprintf(&rev_hex[digits],"%d",fr);
        }
        else
        {
            switch(fr)
            {
            case 10:
                rev_hex[digits] = 'A';
                break;
            case 11:
                rev_hex[digits] = 'B';
                break;
            case 12:
                rev_hex[digits] = 'C';
                break;
            case 13:
                rev_hex[digits] = 'D';
                break;
            case 14:
                rev_hex[digits] = 'E';
                break;
            case 15:
                rev_hex[digits] = 'F';
                break;
            default:
            break;
            }
        }
        cnum /=16;
        digits++;
    }
    result[0] = '0';
    result[1] = 'x';
    for (i = 0; i < digits; i++)
    {
        result[i+2] = rev_hex[digits-i-1];
    }
    return result;
}

//convert ascii to integer
// if not ascii code return -1
int asciiToInt(int ascii)
{
    if ((ascii >=30) && (ascii <=39))
    {
        return ascii-30;
    }
    else
    {
        return -1;
    }
}


/*
 double each odd number in array
*/
void doubleEachOddNumber(int* nums, int numsSize)
{
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2)
        {
            nums[i] = nums[i] << 1;
         }

    }
}

/* function reverses a string */
void reverse_string(char* str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}


int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n - 2);
}



int data[] = {12, 9, 2, 1, 4, 23, 7, 5};//8

int data2[] = {0, 1, 5, 9, 11, 23, 39, 45, 55, 99, 100}; //11
int main()
{
    int num = 0;
    printf("input the number : ");
    scanf("%d", &num);

    printf("\naddNumsInInt : %ld\n", addNumsInInt(num));

    printf("findDiffBetweenMaxAndMin : %d\n", findDiffBetweenMaxAndMin(data, 8));

    printf("countOneBits : %d\n", countOneBits(num));

    printf("binarySearch : %d\n", binarySearch(data2, 11, 33));

    int a = 35;
    int b = 99;

    int* p1 = &a;
    int* p2 = &b;

    printf("*p1:%d; *p2:%d\n", *p1, *p2);

    swapPointers2(&p1, &p2);

    printf("*p1:%d; *p2:%d\n", *p1, *p2);

    return 0;
}
