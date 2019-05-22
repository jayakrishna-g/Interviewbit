/*Question:
Sort List
Asked in:  
Google
Sort a linked list in O(n log n) time using constant space complexity.*/

//Using vector:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    vector<int> v;
    struct ListNode *cur=A;
    while(cur)
    {
        v.push_back(cur->val);
        cur=cur->next;
    }
    cur=A;
    int i=0;
    sort(v.begin(),v.end());
    while(cur)
    {
        cur->val=v[i];
        i++;
        cur=cur->next;
    }
    return A;
}




//BUBBLE Sort:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    struct ListNode *i=A,*j=A;
    for(i=A;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->val>j->val)
            swap(i->val,j->val);
        }
    }
    return A;
}


//Merge Sort:

 
class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return head;

            // find the middle place
            ListNode *p1 = head;
            ListNode *p2 = head->next;
            while(p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            p2 = p1->next;
            p1->next = NULL;

            return mergeTwoLists(sortList(head), sortList(p2)); 
        }

        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;

            ListNode* head = NULL;    // head of the list to return

            // find first element (can use dummy node to put this part inside of the loop)
            if(l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }

            ListNode* p = head;     // pointer to form new list

            while(l1 && l2){
                if(l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }

            // add the rest of the tail, done!
            if (l1) {
                p->next=l1;
            } else {
                p->next=l2;
            }

            return head;
        }
};
