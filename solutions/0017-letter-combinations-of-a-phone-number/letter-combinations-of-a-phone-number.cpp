// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> ans;
    string num2str[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string digits, string prefix){
        if(digits == "") {
            ans.push_back(prefix);
            return;
        }
        int num = digits[0] - '0';
        for(int i = 0;i < num2str[num].length();i++){
            dfs(digits.substr(1), prefix + num2str[num][i]);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        dfs(digits, "");
        return ans;
    }
};
