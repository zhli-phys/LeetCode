class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<bool> used(n);
        used[0] = true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i < n; ++i) 
                pq.push({dist(i, 0, points), i});
        for (int count = n - 1; count > 0; --count) {
            while (used[pq.top().second])
                pq.pop();
            ans += pq.top().first;
            int next = pq.top().second;
            used[next] = true;
            pq.pop();
            for (int i = 0; i < n; ++i)
                if (!used[i])
                    pq.push({dist(i, next, points), i});
        }
        return ans;
    }
    
    int dist(int i, int j, vector<vector<int>>& points) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
};