/*Question:
Flatten Binary Tree to Linked List
Asked in:  
Adobe
Amazon
Microsoft
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

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
TreeNode *head=NULL,*cur;
 void in(TreeNode* A)
 {
     if(A==NULL)
     return ;
     if(!head)
     {
         head=new TreeNode(A->val);
         cur=head;
     }
     else
     {
         head->right=new TreeNode(A->val);
         head=head->right;
     }
     in(A->left);
     in(A->right);
     free(A);
 }
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    head=NULL;
    in(A);
    return cur;
}
