// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// Example 1:
//
//
// Input: [[0,30],[5,10],[15,20]]
// Output: false
//
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: true
//
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        int last_time = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] < last_time) return false;
            last_time = max(last_time, intervals[i][1]);
        }
        return true;
    }
};
