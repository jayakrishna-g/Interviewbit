/*
QUestion:
ZigZag Level Order Traversal BT
Asked in:  
Amazon
Microsoft
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
Seen this question in a real interview before */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    vector<int> temp;
    vector<vector<int>> ret;
    q.push(A);
    q.push(NULL);
    int i=1;
    while(1)
    {
        TreeNode* n=q.front();
        q.pop();
        if(n==NULL)
        {
            if(i%2==0)
            reverse(temp.begin(),temp.end());
            ret.push_back(temp);
            temp.clear();
            if(q.empty())
            return ret;
            q.push(NULL);
            i++;
            continue;
        }
        else
        {
            temp.push_back(n->val);
            if(n->left)
            q.push(n->left);
            if(n->right)
            q.push(n->right);
        }
    }
    return ret;
}
