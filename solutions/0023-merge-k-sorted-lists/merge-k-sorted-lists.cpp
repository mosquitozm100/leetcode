// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
//  
// Example 1:
//
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
//
//
// Example 2:
//
//
// Input: lists = []
// Output: []
//
//
// Example 3:
//
//
// Input: lists = [[]]
// Output: []
//
//
//  
// Constraints:
//
//
// 	k == lists.length
// 	0 <= k <= 10^4
// 	0 <= lists[i].length <= 500
// 	-10^4 <= lists[i][j] <= 10^4
// 	lists[i] is sorted in ascending order.
// 	The sum of lists[i].length won't exceed 10^4.
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
