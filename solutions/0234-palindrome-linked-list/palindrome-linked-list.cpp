// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
//
//
// Input: 1->2
// Output: false
//
// Example 2:
//
//
// Input: 1->2->2->1
// Output: true
//
// Follow up:
// Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode * tmp = head;
        int len = 0;
        vector<int> a;
        while(tmp != NULL) {len++;a.push_back(tmp -> val);tmp = tmp -> next;}
        for(int i = 0; i < a.size();i++){
            int j = a.size() - i - 1;
            if(a[i] != a[j]) return false;
        }
        return true;
    }
};
