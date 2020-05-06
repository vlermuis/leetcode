/*
1305. All Elements in Two Binary Search Trees (Medium)

https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
Runtime: 448 ms, faster than 7.79% of C++ online submissions for All Elements in Two Binary Search Trees.
Memory Usage: 85.7 MB, less than 100.00% of C++ online submissions for All Elements in Two Binary Search Trees.
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
    void inorder_to_vect(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorder_to_vect(root->left, v);
            v.push_back(root->val);
            inorder_to_vect(root->right, v);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        vector<int> dop;
        inorder_to_vect(root1, result);
        inorder_to_vect(root2, dop);
        for (auto i = 0; i < dop.size(); i++)
        {
            auto itr = lower_bound(result.begin(), result.end(), dop[i]);
            result.insert(itr, dop[i]);
        }
        return result;
    }
};