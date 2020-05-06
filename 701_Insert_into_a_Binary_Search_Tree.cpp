/*
701. Insert into a Binary Search Tree (Medium)

https://leetcode.com/problems/insert-into-a-binary-search-tree/
Runtime: 84 ms, faster than 99.19% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 38.3 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *newNode(int item)
    {
        TreeNode *temp =  new TreeNode(item);
        return temp;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return newNode(val);
        if (val < root->val)
        {
            root->left  = insertIntoBST(root->left, val);
        }
        else if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};