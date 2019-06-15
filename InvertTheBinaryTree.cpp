/*Question:
Invert the Binary Tree
Asked in:  
Google
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

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
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)
    return NULL;
    TreeNode *ll,*rl;
    ll=invertTree(A->right);
    rl=invertTree(A->left);
    A->left=ll;
    A->right=rl;
    return A;
}
