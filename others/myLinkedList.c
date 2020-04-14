/*

707
Linked list

*/

#include <stdio.h>
#include <stdlib.h>

 typedef struct  {
    int val;
    struct ListNode *next;
 }listnode;

typedef struct {
    listnode* head;

} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* mylist = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    mylist->head = NULL;
    return mylist;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int idx = 0;
    listnode* current = obj->head;
    while(current != NULL)
    {
        if (idx == index)
        {
            return current->val;
        }
        idx++;
        current = current->next;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj->head == NULL)
    {
        obj->head = (listnode*)malloc(sizeof(listnode));
        obj->head->next = NULL;
        obj->head->val = val;
    }
    else
    {
        listnode* node = (listnode*)malloc(sizeof(listnode));
        node->next = obj->head->next;
        node->val = obj->head->val;
        obj->head->next = node;
        obj->head->val = val;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->head == NULL)
    {
        obj->head = (listnode*)malloc(sizeof(listnode));
        obj->head->next = NULL;
        obj->head->val = val;
    }
    else
    {
        listnode* current = obj->head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        listnode* node = (listnode*)malloc(sizeof(listnode));
        node->next = NULL;
        node->val = val;
        current->next = node;
    }
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int idx = 0;
    listnode* current = obj->head;
    listnode* prev = obj->head;
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    while(current != NULL)
    {
        if (idx == index)
        {
            listnode* node = (listnode*)malloc(sizeof(listnode));
            node->val = val;
            node->next = current;
            prev->next = node;
            return;
        }
        prev = current;
        current = current->next;
        idx++;
    }
    if (idx == index)
    {
        myLinkedListAddAtTail(obj, val);
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int idx = 0;
    listnode* current = obj->head;
    listnode* prev = current;
    listnode* node = NULL;
    if (index == 0)
    {
        if (current->next != NULL)
        {
            node = current->next;
            current->next = node->next;
            current->val = node->val;
            free(node);
        }
        else
        {
            free(current);
        }
        return;
    }
    while(current != NULL)
    {
        if (idx == index)
        {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        idx++;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
     listnode * current = obj->head;
     listnode * ptemp;
    while(current != NULL)
    {
        ptemp = current;
        current = current->next;
        free(ptemp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

/*********************************************************/


void myLinkedListDisplay(MyLinkedList* obj)
{
    listnode * current = obj->head;
    while (current != NULL)
    {
        printf("[%d], ", current->val);
        current = current->next;
    }
    printf("\n");
}
int main()
{
   MyLinkedList* mll = myLinkedListCreate();
    myLinkedListDisplay(mll);

/*    myLinkedListAddAtHead(mll, 3);
    myLinkedListAddAtHead(mll, 2);
    myLinkedListAddAtHead(mll, 1);
*/
    //printf("%d\n", myLinkedListGet(mll, 3));

    myLinkedListAddAtTail(mll, 1);
    myLinkedListAddAtTail(mll, 2);
    myLinkedListAddAtTail(mll, 3);
    myLinkedListDisplay(mll);

    myLinkedListAddAtIndex(mll, 0, 9);
    myLinkedListAddAtIndex(mll, 2, 99);
    myLinkedListAddAtIndex(mll, 4, 999);
    myLinkedListAddAtIndex(mll, 6, 9999);
    myLinkedListDisplay(mll);

    myLinkedListDeleteAtIndex(mll, 0);
    myLinkedListDisplay(mll);

    myLinkedListDeleteAtIndex(mll, 1);
    myLinkedListDisplay(mll);

    myLinkedListDeleteAtIndex(mll, 2);
    myLinkedListDisplay(mll);

    myLinkedListDeleteAtIndex(mll, 3);
    myLinkedListDisplay(mll);

    myLinkedListDeleteAtIndex(mll, 4);
    myLinkedListDisplay(mll);

    myLinkedListFree(mll);

//    free(mll);
    return 0;
}
