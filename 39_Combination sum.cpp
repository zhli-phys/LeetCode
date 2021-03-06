class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path(candidates.size());
        dfs(0, 0, candidates, target, path, ans);
        return ans;
    }
    
    void dfs(int i, int curr, vector<int>& candidates, int target, vector<int>& path, 
             vector<vector<int>>& ans) {
        int n = candidates.size();
        if (curr == target) {
            vector<int> sol;
            for (int j = 0; j < i; ++j) 
                for (int k = 0; k < path[j]; ++k)
                    sol.push_back(candidates[j]);
            ans.push_back(sol);
        }
        else if (i >= n || curr + candidates[i] > target)
            return;
        else {
            for (int j = 0; j <= (target - curr) / candidates[i]; ++j) {
                path[i] = j;
                dfs(i+1, curr + j * candidates[i], candidates, target, path, ans);
            }
        }
    }
};















class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum_sorted(candidates, target, candidates.size() - 1);
    }
    
    vector<vector<int>> combinationSum_sorted(vector<int>& candidates, int target, int right) {
        if (right < 0) {
            vector<vector<int>> sol(0);
            return sol;
        }
        int last = candidates[right];
        if (target < last) 
            return combinationSum_sorted(candidates, target, right - 1);
        if (target == last) {
            vector<vector<int>> sol = combinationSum_sorted(candidates, target, right - 1);
            vector<int> sol_temp(1);
            sol_temp[0] = last;
            sol.push_back(sol_temp);
            return sol;
        }
        unordered_map<int, unordered_map<int, vector<vector<int>>>>::iterator it = combos.find(target);
        if (it != combos.end()) {
            unordered_map<int, vector<vector<int>>>::iterator it2 = it->second.find(right);
            if (it2 != it->second.end())
                return it2->second;
        }
        vector<vector<int>> sol(0);
        for (int i = right; i >= 0; i--) {
            int candi = candidates[i];
            vector<vector<int>> sol_temp = combinationSum_sorted(candidates, target - candi, i);
            for (int j = 0; j < sol_temp.size(); j++)
                sol_temp[j].push_back(candi);
            sol.insert(sol.end(), sol_temp.begin(), sol_temp.end());
        }
        combos[target][right] = sol;
        return sol;
    }
    
private:
    unordered_map<int, unordered_map<int, vector<vector<int>>>> combos;
};