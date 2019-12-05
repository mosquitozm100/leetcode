// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    struct cmp{
        bool operator()(const ListNode * a, const ListNode * b){
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *> , cmp> pq;
        for(int i = 0;i < lists.size();i++){
            if(lists[i] != NULL) pq.push(lists[i]);
        }
        ListNode * pre = new ListNode(0), *tmp = pre;
        while(!pq.empty()){
            ListNode *e = pq.top();pq.pop();
            tmp -> next = e;
            tmp = tmp -> next;
            if(e -> next != NULL) pq.push(e -> next);
        }
        return pre -> next;
    }
};
