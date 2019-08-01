/*Question:
Kth Smallest Element In Tree
Asked in:  
Amazon
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
Seen this question in a real interview before
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
 vector<int> in;
 void ino(TreeNode *A)
 {
     if(A==NULL)
     return ;
     ino(A->left);
     in.push_back(A->val);
     ino(A->right);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    in.clear();
    ino(A);
    return in[B-1];
}
