/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
easy

Runtime: 8 ms, faster than 57.66% of C online submissions for Remove Duplicates from Sorted List.
Memory Usage: 7.8 MB, less than 40.00% of C online submissions for Remove Duplicates from Sorted List.

*/


#include <stdio.h>
#include <stdlib.h>






 struct ListNode {
    int val;
    struct ListNode *next;
 };

typedef struct ListNode listnode;

void display_list(listnode* plist);
void clean_list(listnode* plist);


/*********************************************************/
struct ListNode* deleteDuplicates(struct ListNode* head){

    listnode* pResult = head;
    listnode* prev_node = head;
    listnode* pnext = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    int prev_val = head->val;
    head = head->next;
    while(head != NULL)
    {
        if (head->val == prev_val)
        {
            pnext = head->next;
            free(head);
            prev_node->next = pnext;
            head = pnext;
        }
        else
        {
            prev_node = head;
            prev_val = head->val;
            head = head->next;
        }
    }
    return pResult;
}


/*********************************************************/


void display_list(listnode* plist)
{
    while(plist != NULL)
    {
        printf("%d, ", plist->val);
        plist = plist->next;
    }
}

void display_list_in_reverse(listnode* plist)
{
    if (plist != NULL)
    {
        listnode* prev = plist;
        display_list_in_reverse(plist->next);
        listnode* prev2 = plist;
        if (plist != NULL)
        {
            printf("%d, \n", plist->val);
            if (prev != NULL)
            {
                printf("prev: %d \n", prev->val);
            }
            
        }
    }
    else
    {
        return;
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


listnode* reverseList(listnode* head)
{
    listnode* pprev = NULL;
    listnode* pelement = NULL;
    while(head != NULL)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = head->val;
        pelement->next = pprev;
        pprev = pelement;
        head = head->next;
    }
    return pelement;
}


int data00[] = {1, 1, 2};
int data01[] = {1, 1, 2, 3, 3};

int main()
{
    
    listnode* pStart0 = NULL;
    listnode* pResult = NULL;
/*    
    array_to_list(data00, 3, &pStart0);
    display_list(pStart0);
    printf(" >>> ");
    pResult = deleteDuplicates(pStart0);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pResult);
*/

    array_to_list(data01, 5, &pStart0);
    display_list(pStart0);
    printf(" >>> ");
    pResult = deleteDuplicates(pStart0);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pResult);
/*
    listnode* pReverse0 = reverseList(pStart0);
    printf("another list : ");
    display_list(pReverse0);
    printf("\n");
*/

    
//    clean_list(pReverse0);
    return 0;
}
