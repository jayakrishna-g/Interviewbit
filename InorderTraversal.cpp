/*Question:
Inorder Traversal
Asked in:  
Amazon
Microsoft
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

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
 */
 vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode*> s;
    TreeNode* cur=A;
    while(!s.empty()||cur!=NULL)
    {
        while(cur)
        {
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        ret.push_back(cur->val);
        cur=cur->right;
    }
    return ret;
}
