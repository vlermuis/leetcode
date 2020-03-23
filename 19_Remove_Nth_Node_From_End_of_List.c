/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

19. Remove Nth Node From End of List (Medium)
Runtime: 4 ms, faster than 57.30% of C online submissions for Remove Nth Node From End of List.
Memory Usage: 5.5 MB, less than 100.00% of C online submissions for Remove Nth Node From End of List.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int idx = 0;
    int i;
    struct ListNode * current = head;
    while (current != NULL)
    {
        current = current->next;
        idx++;
    }
    current  = head;
    printf("%d\n", idx);
    if ((idx - n) >= 1)
    {
        for (i = 0; i < (idx - n - 1); i++)
        {
            current = current->next;
        }
        printf("%d\n", current->val);
        struct ListNode * to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);

    }
    else
    {
        struct ListNode * new_head = head->next;
        free(head);
        return new_head;
    }
    return head;

}

