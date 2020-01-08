/*
https://leetcode.com/problems/remove-linked-list-elements/
easy

*/


struct ListNode* removeElements(struct ListNode* head, int val){

    struct ListNode* ret_head = head;
    struct ListNode* prev = NULL;

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
