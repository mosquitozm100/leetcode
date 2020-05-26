// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
//


class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n + 1, 0);
        int ans = 0;
        for(int i = 2;i < n;i++){
            if(isPrime[i] == 0){
                for(int j = i + i;j <= n;j+=i) isPrime[j] = 1;
                ans++;
            }
        }
        return ans;
    }
};
