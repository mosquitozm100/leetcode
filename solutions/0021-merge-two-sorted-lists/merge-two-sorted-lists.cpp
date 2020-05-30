// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * pre = new ListNode(0);
        ListNode * tmp = pre;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val)   {tmp -> next = l1; l1 = l1 -> next;}
            else {tmp -> next = l2;l2 = l2 -> next;}
            tmp = tmp -> next;
        }
        if(l1 != NULL) tmp -> next = l1;
        else tmp -> next = l2;
        return pre -> next;
    }
};
