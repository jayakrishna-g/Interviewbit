/*
Question:
Reverse Link List II
Asked in:  
Facebook
Microsoft
Amazon
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    struct ListNode *s=A,*e=A,*ps=A,*pe=A;
    if(A->next==NULL)
    return A;
    for(int i=1;i<B;i++){
        ps=s;
        s=s->next;
    }
    for(int i=1;i<C;i++){
        pe=e;
        e=e->next;
    }
    if(e)
    pe=e->next;
    else
    pe=e;
    //cout<<s->val<<" "<<e->val<<" "<<ps->val<<" "<<pe->val<<endl;
    struct ListNode *cur=s,*prev=e->next,*next=s->next;
    while(cur!=pe)
    {
        //cout<<prev->val<<" "<<cur->val<<" "<<cur->next->val<<endl;
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    if(s!=A)
    ps->next=prev;
    else
    A=prev;
    //prev->next=ps;
    return A;
}
