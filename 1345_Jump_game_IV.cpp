class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) 
            pos[arr[i]].push_back(i);
        vector<bool> visited(n);
        unordered_set<int> seen;
        queue<int> q;
        q.push(0);
        int step = 0;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int curr = q.front();
                q.pop();
                if (visited[curr])
                    continue;
                visited[curr] = true;
                if (curr == n - 1)
                    return step;
                if (curr > 0 && !visited[curr-1]) 
                    q.push(curr-1);
                if (!visited[curr+1]) 
                    q.push(curr+1);
                if (seen.find(arr[curr]) == seen.end()) {
                    for (int next : pos[arr[curr]]) {
                        if (!visited[next]) 
                            q.push(next);
                    }
                    seen.insert(arr[curr]);
                }                
            }
            ++step;
        }
        return -1;
    }
};