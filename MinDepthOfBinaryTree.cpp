/*Question:
Min Depth of Binary Tree
Asked in:  
Facebook
Amazon
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.

Seen this qu
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
int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
    return 0;
    if(A->right and A->left)
    return 1+min(minDepth(A->right),minDepth(A->left));
    if(A->right)
    return 1+minDepth(A->right);
    if(A->left)
    return 1+minDepth(A->left);
}
