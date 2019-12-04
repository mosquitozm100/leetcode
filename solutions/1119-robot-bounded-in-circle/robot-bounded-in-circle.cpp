// On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:
//
//
// 	"G": go straight 1 unit;
// 	"L": turn 90 degrees to the left;
// 	"R": turn 90 degress to the right.
//
//
// The robot performs the instructions given in order, and repeats them forever.
//
// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
//
//  
//
// Example 1:
//
//
// Input: "GGLLGG"
// Output: true
// Explanation: 
// The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
// When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
//
//
// Example 2:
//
//
// Input: "GG"
// Output: false
// Explanation: 
// The robot moves north indefinitely.
//
//
// Example 3:
//
//
// Input: "GL"
// Output: true
// Explanation: 
// The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
//
//
//  
//
// Note:
//
//
// 	1 <= instructions.length <= 100
// 	instructions[i] is in {'G', 'L', 'R'}
//
//


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0;
        int x = 0, y = 0;
        int dx[] = {0, 1,0,-1};
        int dy[] = {1,0,-1,0};
        int mod = 4;
        for(int i = 0;i < instructions.size();i++){
            char c = instructions[i];
            if(c == 'L') dir = (dir + 4 - 1) % 4;
            else if(c == 'R') dir = (dir + 1) % 4;
            else {
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }
        if(dir != 0 || (x == 0 && y == 0)) return true;
        else return false;
    }
};
