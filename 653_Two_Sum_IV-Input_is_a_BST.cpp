/*
653. Two Sum IV - Input is a BST (Easy)

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Runtime: 80 ms, faster than 7.20% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 22.5 MB, less than 100.00% of C++ online submissions for Two Sum IV - Input is a BST.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

    // A utility function to create a new BST node
    TreeNode *newNode(int item)
    {
        TreeNode *temp =  (TreeNode*)malloc(sizeof(TreeNode));
        temp->val = item;
        temp->left = temp->right = NULL;
        return temp;
    }
    /* A utility function to insert a new node with given key in BST */
    TreeNode* insert(TreeNode* node, int key)
    {
        /* If the tree is empty, return a new node */
        if (node == NULL) return newNode(key);

        /* Otherwise, recur down the tree */
        if (key < node->val)
            node->left  = insert(node->left, key);
        else if (key > node->val)
            node->right = insert(node->right, key);

        /* return the (unchanged) node pointer */
        return node;
    }

    // A utility function to do inorder traversal of BST
    void inorder_to_vect(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorder_to_vect(root->left, v);
            v.push_back(root->val);
            inorder_to_vect(root->right, v);
        }
    }

    void post_order_traversal_and_clean(TreeNode* root)
    {
        if(root != NULL)
        {
            post_order_traversal_and_clean(root->left);
            post_order_traversal_and_clean(root->right);
            free(root);
            root = NULL;
        }
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorder_to_vect(root, vals);
        for (auto itr = vals.begin(); itr != vals.end(); itr++)
        {
            for (auto jtr = vals.begin(); jtr != vals.end(); jtr++)
            {
                if ((itr != jtr) && (*itr + *jtr == k))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Solution solution;

    TreeNode *root = NULL;
    root = solution.insert(root, 50);
    solution.insert(root, 30);
    solution.insert(root, 20);
    solution.insert(root, 40);
    solution.insert(root, 70);
    solution.insert(root, 60);
    solution.insert(root, 80);

    solution.insert(root, 10);
    solution.insert(root, 90);

    cout << solution.findTarget(root, 60) << "\n";

    solution.post_order_traversal_and_clean(root);
    return 0;
}
