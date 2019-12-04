// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || (head -> next == NULL)) return head;
        ListNode *pre = head, *now = head -> next, * post = head -> next -> next;
        while(now != NULL){
            now -> next = pre;
            pre = now;
            now = post;
            if(post != NULL) post = post -> next;
        }
        head -> next = NULL;
        return pre;
    }
};
