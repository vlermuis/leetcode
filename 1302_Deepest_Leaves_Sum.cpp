/*
1302. Deepest Leaves Sum (Medium)

https://leetcode.com/problems/deepest-leaves-sum/
Runtime: 68 ms, faster than 8.38% of C++ online submissions for Deepest Leaves Sum.
Memory Usage: 38.2 MB, less than 100.00% of C++ online submissions for Deepest Leaves Sum.
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
    int checkDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max((1 + checkDepth(root->left)), (1 + checkDepth(root->right)));
    }
    
    int sumDeepLeafs(TreeNode* root, int depth, int max_depth)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (max_depth - 1 == depth)
        {
            return root->val;
        }
        return sumDeepLeafs(root->left, depth + 1, max_depth) + sumDeepLeafs(root->right, depth + 1, max_depth);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return sumDeepLeafs(root, 0, checkDepth(root));
    }
};