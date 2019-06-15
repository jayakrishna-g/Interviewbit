/*
Question:
Postorder Traversal
Asked in:  
Amazon
Microsoft
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * 
 */
 vector<int> ret;
void foo(TreeNode *root)
{
    if(root==NULL)
    return ;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode *n=s.top();
        s.pop();
        ret.push_back(n->val);
        if(n->left)
        s.push(n->left);
        if(n->right)
        s.push(n->right);
    }
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    ret.clear();
    foo(A);
    return ret;
}
