// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//  
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        ListNode * p1 = head , * p2 = head -> next,* pre = NULL;
        head = p2;
        while(p1 != NULL && p2 != NULL){
            p1 -> next = p2 -> next;
            p2 -> next = p1;
            if(pre != NULL) pre-> next= p2;
            pre = p1;
            
            p1 = p1 -> next;
            if(p1 == NULL) break;
            else p2 = p1 -> next;
        }
        return head;
    }
};
