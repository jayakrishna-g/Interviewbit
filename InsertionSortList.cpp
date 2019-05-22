/*Question:
Insertion Sort List
Asked in:  
Microsoft
Google
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.*/

//vector:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::insertionSortList(ListNode *A)
{
    vector<int> v;
    struct ListNode *cur = A;
    while (cur)
    {
        v.push_back(cur->val);
        cur = cur->next;
    }
    cur = A;
    int i = 0;
    sort(v.begin(), v.end());
    while (cur)
    {
        cur->val = v[i];
        i++;
        cur = cur->next;
    }
    return A;
}

//Linked List:

ListNode *insertionSortList(ListNode *head)
{
    if (!head)
        return head;
    if (!head->next)
        return head;

    ListNode *sorted = NULL;
    ListNode *list = head;
    while (list)
    {
        ListNode *curr = list;
        list = list->next;
        if (sorted == NULL || sorted->val > curr->val)
        {
            // first lookup
            curr->next = sorted; //this indicates the end of sorted list
            sorted = curr;
        }
        else
        {
            // insert somewhere after the fisrt of sorted
            ListNode *tmp = sorted;
            while (tmp)
            {
                ListNode *s = tmp;
                tmp = tmp->next;

                if (s->next == NULL || s->next->val > curr->val)
                {
                    s->next = curr;
                    curr->next = tmp;
                    break;
                }
            }
        }
    }
    return sorted;
}