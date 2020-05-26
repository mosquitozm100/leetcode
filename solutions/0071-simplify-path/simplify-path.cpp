// Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
//
// In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.
//
// Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
//
//  
//
// Example 1:
//
//
// Input: "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.
//
//
// Example 2:
//
//
// Input: "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
//
//
// Example 3:
//
//
// Input: "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
//
//
// Example 4:
//
//
// Input: "/a/./b/../../c/"
// Output: "/c"
//
//
// Example 5:
//
//
// Input: "/a/../../b/../c//.//"
// Output: "/c"
//
//
// Example 6:
//
//
// Input: "/a//b////c/d//././/.."
// Output: "/a/b/c"
//
//


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> capath;
        path.erase(0, 1);
        while(path != ""){
            string curstr = "";
            int place = path.find('/');
            //printf("place:  %d\n", place);
            if(place != -1) {
                curstr = path.substr(0,place);
                path.erase(0, place + 1);
            }
            else {curstr = path;path = "";}
            //cout << "path:  " << path << endl;
            if(curstr == ".") {}
            else if(curstr == "..") {if(!capath.empty())  capath.pop_back();}
            else if(curstr == "") {}
            else capath.push_back(curstr);
        }
        string ans;
        if(capath.size() == 0) ans = '/';
        for(int i = 0; i < capath.size();i++){
            ans = ans + '/' + capath[i];
        }
        return ans;
    }
};
