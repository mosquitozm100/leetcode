// You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
//
// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
//
// You need to return the least number of units of times that the CPU will take to finish all the given tasks.
//
//  
// Example 1:
//
//
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.
//
//
// Example 2:
//
//
// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6
// Explanation: On this case any permutation of size 6 would work since n = 0.
// ["A","A","A","B","B","B"]
// ["A","B","A","B","A","B"]
// ["B","B","B","A","A","A"]
// ...
// And so on.
//
//
// Example 3:
//
//
// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16
// Explanation: 
// One possible solution is
// A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
//
//
//  
// Constraints:
//
//
// 	The number of tasks is in the range [1, 10000].
// 	The integer n is in the range [0, 100].
//
//


class Solution {
public:
    struct InQue{
        char task;
        int count;
        
        InQue(char c, int cnt):task(c), count(cnt) {}
        
        bool operator < (const InQue & b) const{
            return count < b.count;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        int numOfTasks = tasks.size();
        priority_queue<InQue> pq;
        unordered_map<char, int> count;
        
        for(int i = 0;i < tasks.size();i++){
            count[tasks[i]]++;
        }
        for(auto it : count) pq.push(InQue(it.first, it.second));
        
        queue<InQue> waitQueue;
        for(int i = 0;i < n;i++) waitQueue.push(InQue('$', 0));
        
        int NumOfFinTasks = 0;
        int ans = 0;
        while(NumOfFinTasks < numOfTasks){
            ans++;
            if(!pq.empty()) {
                InQue e = pq.top();pq.pop();
                //cout << "e: " << e.task << "\t" << e.count << endl;
                waitQueue.push(InQue(e.task, e.count - 1));
                InQue t = waitQueue.front();waitQueue.pop();
                if(t.count > 0) pq.push(t);
                NumOfFinTasks++;
            }
            else{
                waitQueue.push(InQue('$', 0));
                InQue t = waitQueue.front();waitQueue.pop();
                if(t.count > 0) pq.push(t);
            }
        }
        return ans;
    }
};