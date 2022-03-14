class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = split(path, '/');
        vector<string> simplified;
        for (auto& dir : dirs) {
            if (dir == "" || dir == ".")
                continue;
            else if (dir == "..") {
                if (!simplified.empty())
                    simplified.pop_back();
            }
            else 
                simplified.push_back(dir);
        }
        string ans;
        for (auto& s : simplified) {
            ans += '/';
            ans += s;
        }
        return ans == ""? "/" : ans;
    }
    
    vector<string> split(const string& s, char d = ' ') {
        vector<string> ans;
        string curr;
        for (char ch : s) {
            if (ch == d) {
                ans.push_back(curr);
                curr = "";
            }
            else 
                curr.push_back(ch);
        }
        ans.push_back(curr);
        return ans;
    }
};