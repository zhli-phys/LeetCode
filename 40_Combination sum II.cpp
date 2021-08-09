//deep-first search; 4 ms 93%; 11.1 MB 43%
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> mp;
        for (int candidate : candidates)
            ++mp[candidate];
        vector<vector<int>> ans;
        vector<int> path;
        dfs(mp.begin(), mp, target, path, ans);
        return ans;
    }
    
    void dfs(map<int, int>::iterator it, map<int, int>& mp, int target, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (it == mp.end() || it->first > target)
            return;
        int curr = it->first;
        int count = it->second;
        ++it;
        for (int i = 0; i <= count; ++i) {
            if (curr * i > target)
                return;
            for (int j = 0; j < i; ++j) 
                path.push_back(curr);
            dfs(it, mp, target - curr * i, path, ans);
            for (int j = 0; j < i; ++j)
                path.pop_back();
        }
    }
};