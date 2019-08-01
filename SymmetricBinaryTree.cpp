/*Question:
Symmetric Binary Tree
Asked in:  
Amazon
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Seen this question in a real interview before */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool foo(TreeNode *a,TreeNode *b)
 {
     if(a==NULL and b==NULL)
     return true;
     if(a==NULL or b==NULL)
     return false;
     if(a->val!=b->val)
     return false;
     return foo(a->left,b->right) and foo(a->right,b->left);
 }
int Solution::isSymmetric(TreeNode* A) {
    return foo(A,A);
}
