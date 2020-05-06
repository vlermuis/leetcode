/*
700. Search in a Binary Search Tree (Easy)

https://leetcode.com/problems/search-in-a-binary-search-tree/
Runtime: 64 ms, faster than 17.42% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 34.8 MB, less than 9.76% of C++ online submissions for Search in a Binary Search Tree.
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root != nullptr)
        {
            if (root->val == val)
            {
                return root;
            }
            if (val < root->val)
            {
                return searchBST(root->left, val);
            } else if (val > root->val)
            {
                return searchBST(root->right, val);
            }
        }
        return nullptr;
    }
};