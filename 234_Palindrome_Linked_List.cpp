/*
234. Palindrome Linked List (Easy)
https://leetcode.com/problems/palindrome-linked-list/
Runtime: 24 ms, faster than 63.30% of C++ online submissions for Palindrome Linked List.
Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Palindrome Linked List.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    vector<int> backw;
        if (head == NULL)
        {
            return true;
        }
        while(head != NULL)
        {
            backw.push_back(head->val);
            head = head->next;
        }
        for (auto itrs = backw.begin(), itre = backw.end()-1; itrs <= itre; itrs++, itre--)
        {
            if (*itrs != *itre)
            {
                return false;
            }
        }
    return true;
        
    }
};