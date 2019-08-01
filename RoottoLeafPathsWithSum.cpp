/*Question:
Root to Leaf Paths With Sum
Asked in:  
Microsoft
Yahoo
Amazon
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
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
 vector<vector<int>> ret;
 void foo(TreeNode *A,int B,vector<int> &v)
 {
     if(A->left==NULL and A->right==NULL)
     {
         if(B==A->val)
         {
             v.push_back(A->val);
             ret.push_back(v);
             v.pop_back();
         }
         return ;
     }
     if(A->left){
        v.push_back(A->val);
        foo(A->left,B-A->val,v);
        v.pop_back();
     }
     
     if(A->right){
        v.push_back(A->val);
        foo(A->right,B-A->val,v);
        v.pop_back();
     }
 }
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ret.clear();
    vector<int> v;
    foo(A,B,v);
    return ret;
}
