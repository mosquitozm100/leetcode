// On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.
//
// Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
//
// Return the smallest possible value of D.
//
// Example:
//
//
// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
// Output: 0.500000
//
//
// Note:
//
//
// 	stations.length will be an integer in range [10, 2000].
// 	stations[i] will be an integer in range [0, 10^8].
// 	K will be an integer in range [1, 10^6].
// 	Answers within 10^-6 of the true value will be accepted as correct.
//
//


class Solution {
public:
    double eps = 1e-6;
    
    bool check(vector<int> S, int K,double len){
        double now = S[0];
        int cnt = 1;
        while(cnt < S.size()){
            if(S[cnt] - now <= len) {now = S[cnt];cnt++;}
            else {
                if(K == 0) break;
                K--;now += len;
            }
        }
        if(cnt >= S.size()) return true;
        else return false;
    }
        
    double minmaxGasDist(vector<int>& stations, int K) {
        sort(stations.begin(),stations.end());
        double left = 0, right = 1e8 + 5;
        while(right - left >eps){
            double mid = left + (right - left) / 2;
            if(check(stations,K,mid)) right = mid;
            else left = mid;
        }
        return left;
    }
};
