//O(n^2) 20 ms 88%; O(n^2) 19.6 MB 48%
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            int j = 1;
            edges[i-j+1].push_back(i+j);
            while (j <= i && i + j < n) {
                if (s[i-j] == s[i+j])
                    ++j;
                else
                    break;
                edges[i-j+1].push_back(i+j);
            }
        }
        for (int i = 1; i < n; ++i) {
            int j = 1;
            while (i >= j && i + j <= n) {
                if (s[i-j] == s[i+j-1])
                    ++j;
                else
                    break;
                if (j > 1)
                    edges[i-j+1].push_back(i+j-1);
            }           
        }
        vector<int> visited(n);
        queue<int> q;
        q.push(0);
        int cuts = -1;
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; ++i) {
                int curr = q.front();
                if (curr == n)
                    return cuts;
                if (!visited[curr]) {
                    for (int next : edges[curr])
                        q.push(next);
                    visited[curr] = true;
                }
                q.pop();
            }
            ++cuts;
        }
        return -1;
    }
};