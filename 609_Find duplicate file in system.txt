class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto&& path : paths) {
            istringstream ss(path);
            string dir;
            ss >> dir;
            string file;
            while (ss >> file) {    
                size_t m = file.find('(');
                mp[file.substr(m+1, file.size()-m-2)].push_back(dir + '/' +file.substr(0, m));
            }
        }
        for (auto it = mp.begin(); it!= mp.end(); ++it) {
            if (it->second.size() > 1)
                ans.push_back(it->second);
        }
        return ans;
    }
};