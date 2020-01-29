/*
BST Iterator
Asked in:  
Apple
Amazon
Facebook
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 
Seen this ques
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
vector<TreeNode*> v;
void foo(TreeNode *root)
{
    if(root==NULL)
    {
        return ;
    }
    foo(root->left);
    v.push_back(root);
    foo(root->right);
}
int i=0;
BSTIterator::BSTIterator(TreeNode *root) {
    v.clear();
    i=0;
        foo(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return i<v.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    auto ret=v[i]->val;
    i++;
    return ret;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
