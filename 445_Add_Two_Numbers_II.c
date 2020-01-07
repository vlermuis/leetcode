/*
https://leetcode.com/problems/add-two-numbers-ii/
medium

Runtime: 20 ms, faster than 37.18% of C online submissions for Add Two Numbers II.
Memory Usage: 9.9 MB, less than 100.00% of C online submissions for Add Two Numbers II.

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

/*************************************************************/
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
listnode* add_to_list0(int data, listnode* pHead)
{
    listnode* pelement = (listnode*)malloc(sizeof(listnode));
    pelement->val = data;
    pelement->next = pHead;
    return pelement;
}


listnode* reverseList(listnode* head)
{
    listnode* pprev = NULL;
    listnode* pelement = NULL;
    listnode* clean_node = NULL;
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int idx = 0;
    int sum = 0;
    listnode* pResult = NULL;

    listnode* rl1 = reverseList(l1);
    listnode* rl2 = reverseList(l2);

    while((rl1 != NULL) || (rl2 != NULL) || (sum>0))
    {
        if (rl1 != NULL)
        {
            sum += rl1->val;
            rl1 = rl1->next;
        }        
        if (rl2 != NULL)
        {
            sum += rl2->val;
            rl2 = rl2->next;
        } 
        pResult = add_to_list0(sum%10, pResult);
        sum /= 10;
    }

    clean_list(rl1);
    clean_list(rl2);

    return pResult;


}



/*************************************************************/

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
        display_list_in_reverse(plist->next);
        if (plist != NULL)
        {
            printf("%d, ", plist->val);
        }
    }
    else
    {
        return;
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

int data00[] = {7, 2, 4, 3};
int data01[] = {5, 6, 4};



int main()
{
    listnode* pStart0 = NULL;
    listnode* pStart1 = NULL;
    array_to_list(data00, 4, &pStart0);
    array_to_list(data01, 3, &pStart1);


    listnode* pResult = addTwoNumbers(pStart0, pStart1);

    display_list(pResult);
    printf("\n");


    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);




/*    
    listnode* pStart0 = NULL;
    array_to_list(data00, 4, &pStart0);
    printf("direct order : ");
    display_list(pStart0);
    printf("\n");

    printf("reverse order : ");
    display_list_in_reverse(pStart0);
    printf("\n");

    listnode* pReverse0 = reverseList(pStart0);
    printf("another list : ");
    display_list(pReverse0);
    printf("\n");


    clean_list(pStart0);
    clean_list(pReverse0);
*/    
    return 0;
}
