// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//


class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        st.insert(1);
        vector<long> factors = {2, 3, 5};
        long e = 0;
        
        while(n--){
            e = pq.top();pq.pop();
            for(int i = 0;i < factors.size();i++){
                long t = e * factors[i];
                if(st.count(t)) continue;
                st.insert(t);
                pq.push(t);
            }
        }
        return e;
    }
};
