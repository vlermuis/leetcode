/*
* 1290. Convert Binary Number in a Linked List to Integer (Easy)
Runtime: 0 ms, faster than 100.00% of C online submissions for Convert Binary Number in a Linked List to Integer.
Memory Usage: 5.3 MB, less than 100.00% of C online submissions for Convert Binary Number in a Linked List to Integer.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int idx = 0;
    int decn = 0;
    int i;
    int result = 0;
    int idx2 = 0;
    while(head != NULL)
    {
        if (head->val)
        {
            decn |= (1 << idx);
        }
        else
        {
            decn &= ~(1 << idx);
        }
        idx++;
        head = head->next;
    }
    for (i = idx-1; i >= 0;i--)
    {
        if ((1 << i)  &  decn)
        {
            result |= (1 << idx2);
        }
        else
        {
            result &= ~(1 << idx2);
        }
        idx2++;
    }

    return result;

}

