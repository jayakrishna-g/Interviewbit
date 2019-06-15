/*
Question:
Least Common Ancestor
Asked in:  
Facebook
Adobe
Microsoft
Amazon
Google
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
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
 bool search(TreeNode *root,int B)
 {
     if(root==NULL)
     return false;
     if(root->val==B)
     return true;
     return search(root->left,B)||search(root->right,B);
 }
int Solution::lca(TreeNode* A, int B, int C) {
    if(A==NULL)
    return -1;
    if(A->val==B && A->val==C)
    return A->val;
    bool rb=search(A->right,B);
    bool rc=search(A->right,C);
    bool lb=search(A->left,B);
    bool lc=search(A->left,C);
    if(A->val==B)
    {
        if(rc or lc)
        return A->val;
        else 
        return -1;
    }
    if(A->val==C)
    {
        if(lb or rb)
        return A->val;
        else
        return -1;
    }
    if(rb and rc)
    return lca(A->right,B,C);
    if(lb and lc)
    return lca(A->left,B,C);
    if((lb and rc) or (rb and lc))
    return A->val;
    return -1;
}


