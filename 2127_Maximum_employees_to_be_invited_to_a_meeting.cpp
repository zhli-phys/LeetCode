class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> ingoing(n);
        for (int i = 0; i < n; ++i)
            ingoing[favorite[i]].push_back(i);
        vector<bool> used(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && favorite[favorite[i]] == i) 
                ans += explore(i, favorite[i], ingoing, used);
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ans = max(ans, circle(i, favorite, used));
            }
        }
        return ans;
    }
    
    int explore(int i, int j, vector<vector<int>>& ingoing, vector<bool>& used) {
        used[i] = true;
        used[j] = true;
        int left = 0;
        int right = 0;
        for (int next : ingoing[i]) {
            if (next != j)
                left = max(left, length(next, ingoing, used));
        }
        for (int next : ingoing[j]) {
            if (next != i)
                right = max(right, length(next, ingoing, used));
        }
        return left + right + 2;
    }
    
    int length(int num, vector<vector<int>>& ingoing, vector<bool>& used) {
        used[num] = true;
        int ans = 0;
        for (int next : ingoing[num])
            ans = max(ans, length(next, ingoing, used));
        return ans + 1;
    }
    
    int circle(int i, vector<int>& favorite, vector<bool>& used) {
        unordered_set<int> path;
        int start = startOfCircle(i, favorite, path, used);
        if (start < 0)
            return -1;
        else
            return 1 + lengthOfCircle(favorite[start], favorite, start);
    }
    
    int startOfCircle(int i, vector<int>& favorite, unordered_set<int>& path, vector<bool>& used) {
        if (path.find(i) != path.end())
            return i;
        if (used[i])
            return -1;
        used[i] = true;
        path.insert(i);
        return startOfCircle(favorite[i], favorite, path, used);
    }
    
    int lengthOfCircle(int curr, vector<int>& favorite, int start) {
        if (curr == start)
            return 0;
        else
            return 1 + lengthOfCircle(favorite[curr], favorite, start);
    }
};