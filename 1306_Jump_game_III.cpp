class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        return dfs(arr, start, visited);
    }
    
    bool dfs(vector<int>& arr, int start, vector<bool>& visited) {
        if (start < 0 || start >= arr.size() || visited[start])
            return false;
        if (arr[start] == 0)
            return true;
        visited[start] = true;
        return dfs(arr, start - arr[start], visited) || dfs(arr, start + arr[start], visited);
    }
};