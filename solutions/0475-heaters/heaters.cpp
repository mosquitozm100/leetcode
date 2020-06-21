// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
//
// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
//
// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
//
// Note:
//
//
// 	Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// 	Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// 	As long as a house is in the heaters' warm radius range, it can be warmed.
// 	All the heaters follow your radius standard and the warm radius will the same.
//
//
//  
//
// Example 1:
//
//
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
//
//
//  
//
// Example 2:
//
//
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
//
//
//  
//


class Solution {
public:
    bool is_valid(vector<int> & houses, vector<int> & heaters, int range){
        int curIdxHeaters = 0;
        
        for(int i = 0;i < houses.size();i++){
            while(curIdxHeaters < heaters.size() && heaters[curIdxHeaters] < houses[i] && heaters[curIdxHeaters] + range < houses[i]) 
                curIdxHeaters++;
            if(curIdxHeaters >= heaters.size()) return false;
            if(heaters[curIdxHeaters] >= houses[i] && houses[i] + range < heaters[curIdxHeaters]) 
                return false;
        }
        return true;
    }
     
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        // Write your code here
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        //cout << 1 << endl;
        int left = 0;
        int right = 1e9 + 7;
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            //cout << 3 << endl;
            //cout << left << '\t' << right << endl;
            if(is_valid(houses, heaters, mid)) right = mid;
            else left = mid;
            //cout << 4 << endl;
        }
        
        //cout << 2 << endl;
        if(is_valid(houses, heaters, left)) return left;
        else return right;
    }
};
