/*
https://leetcode.com/problems/add-two-numbers/
medium
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

/****Result function bellow *****************************************************/
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int idx = 0;
    int sum = 0;
    listnode* pResult = NULL;

    while((l1 != NULL) || (l2 != NULL) || (sum>0))
    {
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }        
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        } 
        add_to_list(sum%10, &pResult);
        sum /= 10;
    }


    return pResult;
}
/********************************************************************************/
/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    unsigned long n1 = make_number_from_list(l1);
    unsigned long n2 = make_number_from_list(l2);
    
    unsigned long numr = n1 + n2;

    printf("n1:%d ; n2:%d ; numr:%d ;\n", n1, n2, numr);



//    unsigned long numr = make_number_from_list(l1) + make_number_from_list(l2);

    return digits_from_num_to_linkedlist_reverse(numr);

}
*/


long powerFast(long num, long deg) {
    long result = 1;
    while(deg) {
        if (deg % 2 == 0) {
            deg /= 2;
            num *= num;
        }
        else {
            deg--;
            result *= num;
        }
    }

    return result;
}

unsigned long make_number_from_list(listnode* plist)
{
    int idx = 0;
    int result = 0;

    while(plist != NULL)
    {
        result += powerFast(10, idx++)*plist->val;
        plist = plist->next;
    }
    return result;
}

listnode* digits_from_num_to_linkedlist_reverse(unsigned long num)
{
    listnode* pprev = NULL;
    listnode* pelement = NULL;

    int temp[32] = {0};
    int temp1[32] = {0};
    int temp_size = 0;
    int i = 0;

    if (num == 0)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = 0;
        pelement->next = NULL;
        return pelement;
    }


    div_t q = div(num, 10);

    while((q.quot > 0) || (q.rem > 0))
    {
        temp[i++] = q.rem;
        temp_size++;
        q = div(q.quot, 10);
    }

    for (i = 0; i < temp_size; i++)
    {
        temp1[i] = temp[temp_size-i-1];
    }

    for (i = 0; i <  temp_size; i++)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = temp1[i];
        pelement->next = pprev;
        pprev = pelement;
    }
    return pelement;
}

/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int num1 = make_number_from_list(l1);
    int num2 = make_number_from_list(l2);
    int numr = num1 + num2;
    printf("num1:%d; num2:%d; numr:%d\n", num1, num2, numr);
    
    listnode* p1 = digits_from_num_to_linkedlist(numr);
    display_list(p1);
    printf("\n");
    listnode* p2 = reverseList(p1);
    display_list(p2);
    printf("\n");

    clean_list(p1);

    return p2;
//    return reverseList(digits_from_num_to_linkedlist(numr));
}
*/
/* something wrong with this function */
listnode* digits_from_num_to_linkedlist_reverse_(int num)
{
   
    listnode* pstart = NULL;
    listnode* pprev = NULL;
    listnode* pelement = NULL;
    if (num == 0)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = 0;
        pelement->next = NULL;
        return pelement;
    }

    div_t q = div(num, 10);

    pelement = (listnode*)malloc(sizeof(listnode));
    pstart = pelement;
    pelement->val = q.rem;
    pprev = pelement;

    q = div(q.quot, 10);
    while((q.quot > 0) || (q.rem > 0))
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = q.rem;
        pprev->next = pelement;
        pprev = pelement;
        q = div(q.quot, 10);
    }
    return pstart;
}


listnode* digits_from_num_to_linkedlist(int num)
{
    listnode* pprev = NULL;
    listnode* pelement = NULL;

    if (num == 0)
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = 0;
        pelement->next = NULL;
        return pelement;
    }
    div_t q = div(num, 10);

    while((q.quot > 0) || (q.rem > 0))
    {
        pelement = (listnode*)malloc(sizeof(listnode));
        pelement->val = q.rem;
        pelement->next = pprev;
        pprev = pelement;
        q = div(q.quot, 10);
    }
    return pelement;
}



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
/********************************************************************************/

int data00[] = {3, 4, 2};
int data01[] = {4, 6, 5};

int data10[] = {2};
int data11[] = {};

int data20[] = {0};
int data21[] = {0};

int data30[] = {9};
int data31[] = {9,9,9,9,9,9,9,9,9,1};


int data40[] = {2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9};
int data41[] = {5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9};



int main()
{
    
    listnode* pStart0 = NULL;
    listnode* pStart1 = NULL;
    listnode* pResult = NULL; 
    pStart0 = array_to_linkedlist(data00, 3);
    pStart1 = array_to_linkedlist(data01, 3);
    pResult = addTwoNumbers(pStart0, pStart1);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);

    pStart0 = array_to_linkedlist(data10, 1);
    pStart1 = array_to_linkedlist(data11, 0);
    pResult = addTwoNumbers(pStart0, pStart1);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);

    pStart0 = array_to_linkedlist(data20, 1);
    pStart1 = array_to_linkedlist(data21, 1);
    pResult = addTwoNumbers(pStart0, pStart1);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);

    pStart0 = array_to_linkedlist(data30, 1);
    pStart1 = array_to_linkedlist(data31, 10);
    pResult = addTwoNumbers(pStart0, pStart1);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);

    pStart0 = array_to_linkedlist(data40, 61);
    pStart1 = array_to_linkedlist(data41, 61);
    pResult = addTwoNumbers(pStart0, pStart1);
    display_list(pResult);
    printf("\n");
    clean_list(pStart0);
    clean_list(pStart1);
    clean_list(pResult);


/*  
    display_list(pStart);
    printf("\n");

    printf("{2, 4, 3}: %d\n", make_number_from_list(pStart));


    int rnum = 807;
    div_t q = div(807, 10);
    printf("q.quot:%d; q.rem:%d;\n", q.quot, q.rem);

    div_t q = div(8, 10);
    printf("q.quot:%d; q.rem:%d;\n", q.quot, q.rem);
*/


/*
    int n = 807;
    listnode* pNum = digits_from_num_to_linkedlist_reverse(n);
    display_list(pNum);
    printf("\n");
    clean_list(pNum);
*/
/*
    int n = 807;
    int n1 = n%10;
    int n2 = n/10;
    printf("n1:%d; n2:%d;\n", n1, n2);
*/
    return 0;
}