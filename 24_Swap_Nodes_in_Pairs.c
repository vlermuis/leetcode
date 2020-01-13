/*
https://leetcode.com/problems/swap-nodes-in-pairs/
medium

Runtime: 0 ms, faster than 100.00% of C online submissions for Swap Nodes in Pairs.
Memory Usage: 7.2 MB, less than 50.00% of C online submissions for Swap Nodes in Pairs.


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

struct ListNode* swapPairs(struct ListNode* head){

    listnode* pResult  = NULL;
    listnode** pnext = NULL;
    listnode* a = NULL;
    listnode* b = NULL;
    listnode* c = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    a = head;
    b = head->next;
    c = head->next->next;

    head = b;
    head->next = a;
    head->next->next = c;

    pResult = head;

    pnext = &(head->next->next);

    head = head->next->next;

    while (head != NULL)
    {
        if (head->next == NULL)
        {
            break;
        }
        a = head;
        b = head->next;
        c = head->next->next;


        head = b;
        head->next = a;
        head->next->next = c;
        (*pnext) = head;
        pnext = &(head->next->next);
        head = c;

    }
    return pResult;
}



/*********************************************************/
struct ListNode* removeElements(struct ListNode* head, int val)
{
    listnode* ret_head = head;
    listnode* prev = NULL;

    if (head->val == val)
    {
        ret_head = head->next;
        free(head);
        head = ret_head;
    }
    
    prev = head;
    while(head != NULL)
    {
        if (head->val == val)
        {
            prev->next = head->next;
            free(head);
        }
        prev = head;
        head = head->next;
    }
    return ret_head;
}





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


int data00[] = {1, 2};
int data01[] = {1, 2, 3, 4};
int data02[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int data03[] = {1};
int data04[] = {1, 2, 3};

void test_swapPairs(int * data_num, int data_num_size)
{
    listnode* pStart0 = NULL;
    array_to_list(data_num, data_num_size, &pStart0);
    display_list(pStart0);
    printf(" >>> ");
    pStart0 = swapPairs(pStart0);
    display_list(pStart0);
    printf("\n");
    clean_list(pStart0);

}

int main()
{
    
    listnode* pStart3 = NULL;

    test_swapPairs(data00, 2);
    test_swapPairs(data01, 4);
    test_swapPairs(data02, 10);

    printf(" NULL >>> ");
    pStart3 = swapPairs(NULL);
    display_list(pStart3);
    printf("\n");
    clean_list(pStart3);

    test_swapPairs(data03, 1);
    test_swapPairs(data04, 3);


/*
    listnode* pReverse0 = reverseList(pStart0);
    printf("another list : ");
    display_list(pReverse0);
    printf("\n");
*/

    
//    clean_list(pReverse0);
    return 0;
}
