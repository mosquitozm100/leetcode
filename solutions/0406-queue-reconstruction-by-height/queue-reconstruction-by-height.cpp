// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
// Note:
// The number of people is less than 1,100.
//  
//
// Example
//
//
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
//
//  
//


class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int> > ans;
        vector<pair<int, int> > temp = people;
        for(int i = 0;i < people.size();i++){
            pair<int, int> pick;pick.first = 1000000000;pick.second = 0;
            int p = 0;
            for(int now = 0;now < people.size();now++){//auto it = people.begin();it != people.end(); it++){
                auto it = &people[now];
                if((*it).first < pick.first && (*it).second == 0){
                    pick = (*it);
                    p = now;
                }
            }
            ans.push_back(temp[p]);
//            ans.push_back(p - people.begin() + temp.begin());
            (people[p]).second = -1;
            for(auto it = people.begin();it != people.end(); it++){
                if((*it).first <= pick.first && (*it).second > 0){
                    (*it).second--;
                }
            }
        }
        return ans;
    }
};
