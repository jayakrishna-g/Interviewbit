/*QUestion:
Remove Duplicates from Sorted List
Asked in:  
Microsoft
VMWare
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *cur=A;
    ListNode *prev=A;
    while(cur!=NULL)
    {
        prev=cur;
        while(cur->next and cur->val==cur->next->val)
        {
            cur=cur->next;
        }
        prev->next=cur->next;
        cur=cur->next;
    }
    return A;
}
