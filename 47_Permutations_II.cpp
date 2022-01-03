class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            ++mp[num];
        vector<int> curr;
        vector<vector<int>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) 
            dfs(it->first, curr, ans, mp, nums.size());
        return ans;
    }
    
    void dfs(int num, vector<int>& curr, vector<vector<int>>& ans, unordered_map<int, int>& mp, int n) {
        curr.push_back(num);
        if (curr.size() == n) {
            ans.push_back(curr);
        }
        else {
            --mp[num];
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                if (it->second > 0)
                    dfs(it->first, curr, ans, mp, n);
            }
            ++mp[num];
        }
        curr.pop_back();
    }
};