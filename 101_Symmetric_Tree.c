/*
https://leetcode.com/problems/symmetric-tree/
 (Easy)
*/

#include <stdio.h>


typedef int bool;

#define true 1
#define false 0


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

/* answer bellow */

bool isMirrow(struct TreeNode* lefttree, struct TreeNode* rightree)
{
    if ((lefttree == NULL) && (rightree == NULL)) 
    {
        return true;
    }
    if ((lefttree == NULL) || (rightree == NULL)) 
    {
        return false;
    }

    if ((lefttree->val == rightree->val) &&
        isMirrow(lefttree->right, rightree->left) &&
        isMirrow(lefttree->left, rightree->right))
        {
            return true;
        }
        else
        {
            return false;
        }
}

bool isSymmetric(struct TreeNode* root)
{
    return isMirrow(root, root);
}





/*________________________________________________________*/

void insert(int data) 
{
   struct TreeNode *tempNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
   struct TreeNode *current;
   struct TreeNode *parent;

   tempNode->val = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //if tree is empty
   if(root == NULL) 
   {
      root = tempNode;
   } else 
   {
      current = root;
      parent = NULL;

      while(1) 
      { 
         parent = current;
         
         //go to left of the tree
         if(data < parent->val) 
         {
            current = current->left;                
            
            //insert to the left
            if(current == NULL) 
            {
               parent->left = tempNode;
               return;
            }
         }  //go to right of the tree
         else 
         {
            current = current->right;

            //insert to the right
            if(current == NULL) 
            {
               parent->right = tempNode;
               return;
            }
         }
      }            
   }
}

void post_order_traversal_and_clean(struct TreeNode* root) 
{
   if(root != NULL) 
   {
      post_order_traversal_and_clean(root->left);
      post_order_traversal_and_clean(root->right);
      free(root);
      root = NULL;      
   }
}

/*________________________________________________________*/

int test_case0[] = {1,2,2,3,4,4,3};

int test_case1[] = {1,2,2,-1,3,-1,3};

int main()
{
    int i = 0;
    /* test case 0 */
    for (i = 0; i < 7; i++)
    {
        insert(test_case0[i]);
    }


    post_order_traversal_and_clean(root);

    /* test case 1 */

    return 0;
}