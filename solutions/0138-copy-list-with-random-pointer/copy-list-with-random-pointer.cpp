// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.
//
// The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
//
//
// 	val: an integer representing Node.val
// 	random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
//
//
//  
// Example 1:
//
//
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//
//
// Example 2:
//
//
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
//
//
// Example 3:
//
//
//
//
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
//
//
// Example 4:
//
//
// Input: head = []
// Output: []
// Explanation: Given linked list is empty (null pointer), so return null.
//
//
//  
// Constraints:
//
//
// 	-10000 <= Node.val <= 10000
// 	Node.random is null or pointing to a node in the linked list.
// 	Number of Nodes will not exceed 1000.
//
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node *, Node *> old2new;
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node * tmp = head;
        Node* ansHeadPre = new Node();
        Node * pretmp = ansHeadPre;
        while(tmp != NULL){
            printf("tmp: %d\n", tmp -> val);
            pretmp -> next = new Node();
            pretmp = pretmp -> next;
            pretmp -> val = tmp -> val;
            pretmp -> next = NULL;
            old2new[tmp] = pretmp;
            tmp = tmp -> next;
        }
        pretmp = ansHeadPre; tmp = head;
        while(tmp != NULL){
            pretmp = pretmp -> next;
            printf("pretmp: %d\n", pretmp -> val);
            if(tmp -> random != NULL) pretmp -> random = old2new[tmp -> random];
            else pretmp -> random = NULL;
            tmp = tmp -> next;
        }
        printf("ansHeadPre -> next -> val: %d\n", ansHeadPre -> next -> val);
        return ansHeadPre -> next;
    }
};
