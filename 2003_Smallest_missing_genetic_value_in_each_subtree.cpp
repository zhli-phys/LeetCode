class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> children;
        for (int i = 1; i < n; ++i)
            children[parents[i]].insert(i);
        vector<int> ans(n, 1);
        vector<bool> contain(n+1, false);
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                index = i;
                break;
            }
        }
        vector<bool> visited(n, false);
        while (index >= 0) {
            dfs(index, children, contain, visited, nums);
            while (ans[index] <= n && contain[ans[index]])
                ++ans[index];
            if (parents[index] >= 0)
                ans[parents[index]] = ans[index];
            index = parents[index];
        }
        return ans;
    }
    
    void dfs(int index, unordered_map<int, unordered_set<int>>& children, 
             vector<bool>& contain, vector<bool>& visited, vector<int>& nums) {
        if (visited[index])
            return;
        auto it = children.find(index);
        if (it != children.end()) {
            for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
                dfs(*it1, children, contain, visited, nums);
            }
        }
        if (nums[index] >= 1 && nums[index] <= nums.size())
            contain[nums[index]] = true;
        visited[index] = true;
    }
};