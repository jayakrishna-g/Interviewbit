/*
Question:
Sum Root to Leaf Numbers
Asked in:  
Google
Microsoft
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

Seen thi
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
 int ret;
 void foo(TreeNode* A,int n)
 {
     int pass=n*10+A->val;
     pass=pass%1003;
     if(A->left==NULL and A->right==NULL){
        // cout<<n<<endl;
         ret+=(pass%1003);
         ret=ret%1003;
     return ;
     }
     if(A->left)
     foo(A->left,pass);
     if(A->right)
     foo(A->right,pass);
 }
int Solution::sumNumbers(TreeNode* A) {
    ret=0;
    foo(A,0);
    return ret;
}
