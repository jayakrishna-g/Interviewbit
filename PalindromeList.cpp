/*Question:
Palindrome List
Asked in:  
Amazon
Microsoft
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    struct ListNode *fp=A,*sp=A;
    stack<int> s;
    while(fp){
    s.push(fp->val);
    fp=fp->next;
    }
    while(sp)
    {
        if(sp->val!=s.top())
        return 0;
        sp=sp->next;
        s.pop();
    }
    return 1;
}
