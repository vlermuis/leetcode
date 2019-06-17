/*
https://leetcode.com/problems/reverse-linked-list/
Easy
*/
#include <stdio.h>

 struct ListNode {
    int val;
    struct ListNode *next;
 };

typedef struct ListNode listnode;


/****Result function bellow *****************************************************/
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* pprev = NULL;
    struct ListNode* pelement = NULL;
    while(head != NULL)
    {
        pelement = (struct ListNode*)malloc(sizeof(struct ListNode));
        pelement->val = head->val;
        pelement->next = pprev;
        pprev = pelement;
        head = head->next;
    }
    return pelement;
}
/*********************************************************/
listnode* array_to_linkedlist(int* data, int data_size)
{
    int i = 0;
    listnode* pprev = NULL;
    listnode* pelement = NULL;
    for (i = 0; i <  data_size; i++)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = data[i];
        pelement->next = pprev;
        pprev = pelement;
    }
    return pelement;
}


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



int test_data1[] = {5, 4, 3, 2, 1};
int test_data2[] = {9};

int test_data3[10000] = {0};

int main()
{
    int i = 0;

    listnode* pStart = NULL;
    listnode* pReversedList = NULL;


    pStart = array_to_linkedlist(test_data1, 5);
    display_list(pStart);
    printf("\n");
    pReversedList = reverseList(pStart);
    display_list(pReversedList);
    printf("\n");
    clean_list(pReversedList);
    clean_list(pStart);

    pStart = array_to_linkedlist(test_data2, 1);
    display_list(pStart);
    printf("\n");
    pReversedList = reverseList(pStart);
    display_list(pReversedList);
    printf("\n");
    clean_list(pReversedList);
    clean_list(pStart);


    for (i = 0; i < 10000; i++)
    {
        test_data3[i] = i;
    }

    pStart = array_to_linkedlist(test_data3, 10000);
    display_list(pStart);
    printf("\n");
    pReversedList = reverseList(pStart);
    display_list(pReversedList);
    printf("\n");
    clean_list(pReversedList);
    clean_list(pStart);

    return 0;
}

