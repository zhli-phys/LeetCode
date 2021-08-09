//dfs; 16 ms 27%; O(2^n) 30.3 MB 16%
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int N = static_cast<int>(pow(2, n) + 0.5);
        vector<bool> used(N, false);
        ans.push_back(0);
        used[0] = true;
        dfs(n, ans, used);
        return ans;
    }
    
    bool dfs(int n, vector<int>& ans, vector<bool>& used) {
        int N = used.size();
        if (ans.size() == N)
            return true;
        int curr = ans.back();
        for (int i = 0; i < n; ++i) {
            int next = curr ^ (1 << i);
            if (!used[next]) {
                ans.push_back(next);
                used[next] = true;
                if (dfs(n, ans, used))
                    return true;
                used[next] = false;
                ans.pop_back();
            }
        }
        return false;
    }
};