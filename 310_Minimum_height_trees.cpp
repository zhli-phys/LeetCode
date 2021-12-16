class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        else if (n == 2)
            return {0, 1};
        vector<unordered_set<int>> edgs(n);
        for (auto& edge : edges) {
            edgs[edge[0]].insert(edge[1]);
            edgs[edge[1]].insert(edge[0]);
        }
        unordered_set<int> center(n);
        for (int i = 0; i < n; ++i)
            center.insert(i);
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (edgs[i].size() == 1)
                q.push(i);
        while (center.size() > 2) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int curr = q.front();
                q.pop();
                center.erase(curr);
                int next = *edgs[curr].begin();
                edgs[next].erase(curr);
                if (edgs[next].size() == 1)
                    q.push(next);
            }
        }
        vector<int> ans;
        for (int node : center)
            ans.push_back(node);
        return ans;
    }
};




















class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        else if (n == 2)
            return {0, 1};
        vector<unordered_set<int>> edgs(n);
        for (auto& edge : edges) {
            edgs[edge[0]].insert(edge[1]);
            edgs[edge[1]].insert(edge[0]);
        }
        vector<int> height(n, -1);
        int curr = 0;
        while (edgs[curr].size() == 1)
            ++curr;
        dfs(curr, edgs, height);
        return explore(curr, edgs, height);
    }
    
    int dfs(int i, vector<unordered_set<int>>& edgs, vector<int>& height) {
        if (height[i] < -1)
            return -1;
        height[i] = -2;
        int ans = 0;
        for (int next : edgs[i]) {
            ans = max(ans, dfs(next, edgs, height) + 1);
        }
        height[i] = ans;
        return ans;
    }
    
    vector<int> explore(int curr, vector<unordered_set<int>>& edgs, vector<int>& height) {
        pair<int, int> firstMax = {-1, -1};
        pair<int, int> secondMax = {-1, -1};
        for (int next : edgs[curr]) {
            if (height[next] > firstMax.first) {
                secondMax = firstMax;
                firstMax = {height[next], next};
            }
            else if (height[next] > secondMax.first) {
                secondMax = {height[next], next};
            }
        }
        if (firstMax.first == secondMax.first)
            return {curr};
        else if (firstMax.first == secondMax.first + 1) 
            return {curr, firstMax.second};
        else {
            height[curr] = secondMax.first + 1;
            return explore(firstMax.second, edgs, height);
        }
    }
};