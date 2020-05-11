/*
1008. Construct Binary Search Tree from Preorder Traversal (Medium)

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Runtime: 8 ms, faster than 40.02% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
Memory Usage: 10.9 MB, less than 85.71% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
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
        if (root == nullptr)
        {
            return newNode(val);
        }
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
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (auto x : preorder)
        {
            root = insertIntoBST(root, x);
        }
        return root;
        
    }
};