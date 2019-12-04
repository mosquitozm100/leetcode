// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0.
// queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
// According to the example above:
//
//
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//  
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
//


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> str2num;
        vector<string> strs;
        for(int i = 0;i < equations.size();i++){
            vector<string> &tmp = equations[i];
            if(!str2num.count(tmp[0])) {strs.push_back(tmp[0]);str2num[tmp[0]] = strs.size() - 1;}
            if(!str2num.count(tmp[1])) {strs.push_back(tmp[1]);str2num[tmp[1]] = strs.size() - 1;}
        }
        int n = strs.size();
        vector<vector<double> > myMap(n, vector<double>(n, -1));
        for(int i = 0;i < equations.size();i++){
            vector<string> &tmp = equations[i];
            int num1 = str2num[tmp[0]];
            int num2 = str2num[tmp[1]];
            myMap[num1][num2] = values[i];
            myMap[num2][num1] = 1 / values[i];
        }
        
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(myMap[i][k] != -1 && myMap[k][j] != -1)
                        myMap[i][j] = myMap[i][k] * myMap[k][j];
                }
            }
        }
        vector<double> ans;
        for(int i = 0;i < queries.size();i++){
            if(!str2num.count(queries[i][0]) || !str2num.count(queries[i][1])) ans.push_back(-1);
            else ans.push_back(myMap[str2num[queries[i][0]]][str2num[queries[i][1]]]); 
        }
        return ans;
    }
};
