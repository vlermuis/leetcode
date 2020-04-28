/*
938. Range Sum of BST (Easy)

https://leetcode.com/problems/range-sum-of-bst/
Runtime: 156 ms, faster than 75.34% of C++ online submissions for Range Sum of BST.
Memory Usage: 38.6 MB, less than 100.00% of C++ online submissions for Range Sum of BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int result = 0;
        if (root == NULL)
        {
            return 0;
        }
        if ((root->val >= L) && (root->val <= R))
        {
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
        else if (root->val < L)
        {
            return rangeSumBST(root->right, L, R);
        } else
        {
            return rangeSumBST(root->left, L, R);
        }
        return result;
    }
};