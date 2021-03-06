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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
        TreeNode *temp =  new TreeNode(item);
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

    void preorder_to_vect(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            v.push_back(root->val);
            preorder_to_vect(root->left, v);
            preorder_to_vect(root->right, v);
        }
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
    void postorder_to_vect(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            postorder_to_vect(root->left, v);
            postorder_to_vect(root->right, v);
            v.push_back(root->val);
        }
    }


    void post_order_traversal_and_clean(TreeNode* root)
    {
        if(root != NULL)
        {
            post_order_traversal_and_clean(root->left);
            post_order_traversal_and_clean(root->right);
            delete root;
            root = NULL;
        }
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorder_to_vect(root, vals);
        int r = vals.size() -1;
        int l = 0;
        while (l < r)
        {
            if (vals[l] + vals[r] == k)
            {
                return true;
            }
            else if (vals[l] + vals[r] < k)
            {
                l++;
            } else
            {
                r--;
            }
        }
        return false;

    }

    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {

        if (root)
        {
            int rl = sumEvenGrandparent(root->left, root->val, p);
            int rr = sumEvenGrandparent(root->right, root->val, p);
            int ra;
            if (gp % 2  == 1)
                ra = 0;
            else
                ra= root->val;

        } else
        {
            return 0;
        }
    }
/*************************************************************************/

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
/* test case supprot */

    void display_vect(vector<int> v)
    {
        for (auto x : v)
        {
            cout << x << ", ";
        }
        cout << "\n";
    }

    void testcase_getAllElements(vector<int> vtree1, vector<int> vtree2)
    {
        TreeNode *root1 = NULL;
        TreeNode *root2 = NULL;
        vector<int> result;
        result.clear();

        for (auto i = 0; i < vtree1.size(); i++)
        {
            root1 = insert(root1, vtree1[i]);
        }
        for (auto i = 0; i < vtree2.size(); i++)
        {
            root2 = insert(root2, vtree2[i]);
        }
        result = getAllElements(root1, root2);
        display_vect(result);
        result.clear();
        post_order_traversal_and_clean(root1);
        post_order_traversal_and_clean(root2);
    }


};

void display_vect(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << ", ";
    }
    cout << "\n";
}



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

//    cout << solution.findTarget(root, 60) << "\n";

/*    TreeNode *result = solution.searchBST(root, 66);
    if (result != NULL)
    {
        cout << "found : " << result->val << "\n";
    } else
    {
        cout << "not found\n";
    }
*/
/*
    vector<int> tree_vect;
    tree_vect.clear();

    solution.inorder_to_vect(root, tree_vect);
    display_vect(tree_vect);
    tree_vect.clear();
*/
/*
    solution.testcase_getAllElements({2,1,4},{1,0,3});
    solution.testcase_getAllElements({0,-10,10},{5,1,7,0,2});
    solution.testcase_getAllElements({},{5,1,7,0,2});
    solution.testcase_getAllElements({0,-10,10},{});
*/
/**************/
/*
    TreeNode *root1 = NULL;
    TreeNode *root2 = NULL;
    vector<int> result;
    result.clear();

    vector<int> vtree1{2,1,4};
    vector<int> vtree2{1,0,3};
    for (auto i = 0; i < vtree1.size(); i++)
    {
        root1 = solution.insert(root1, vtree1[i]);
    }
    for (auto i = 0; i < vtree2.size(); i++)
    {
        root2 = solution.insert(root2, vtree2[i]);
    }
    result = solution.getAllElements(root1, root2);
    display_vect(result);
    result.clear();
    solution.post_order_traversal_and_clean(root1);
    solution.post_order_traversal_and_clean(root2);
*/






    solution.post_order_traversal_and_clean(root);

    return 0;
}
