// You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
//
// Write a function to compute all possible states of the string after one valid move.
//
// Example:
//
//
// Input: s = "++++"
// Output: 
// [
//   "--++",
//   "+--+",
//   "++--"
// ]
//
//
// Note: If there is no valid move, return an empty list [].
//


class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if(s == "") return ans;
        for(int i= 0;i < s.size() - 1;i++){
            if(s[i] == '+' && s[i + 1] == '+') {
                ans.push_back(s.substr(0, i) + "--" + s.substr(i + 2));
            }
        }
        return ans;
    }
};
