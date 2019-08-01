/*
Question:
Balanced Binary Tree
Asked in:  
Amazon
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 
Seen this question in a real interview beforeYesNo
Share this    
Notes
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 map<TreeNode*,int> m;
 int height(TreeNode* root)
 {
     if(root==NULL)
     return 0;
     return m[root]=1+max(height(root->left),height(root->right));
 }
 bool isbal(TreeNode *A)
 {
     return abs(m[A->left]-m[A->right])<=1;
 }
 bool foo(TreeNode* A)
 {
     if(A==NULL)
     return true;
     if(!isbal(A))
     return false;
     return foo(A->left)&&foo(A->right);
 }
int Solution::isBalanced(TreeNode* A) {
    m.clear();
    height(A);
    return foo(A);
}
