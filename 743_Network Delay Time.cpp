class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<unordered_set<int>> edges(N);
        vector<vector<int>> length(N, vector<int>(N, -1));
        int E = times.size();
        for (int i = 0; i < E; i++) {       
            edges[times[i][0]-1].insert(times[i][1]-1);
            length[times[i][0]-1][times[i][1]-1] = times[i][2];
        }
        vector<int> T(N, -1);
        vector<bool> visited(N, false);
        T[K-1] = 0;
        for (int i = 0; i < N; i++) {
            int t = INT_MAX;
            int curr = -1;
            for (int j = 0; j < N; j++) {
                if (!visited[j] && T[j] >= 0 && T[j] < t) {
                    t = T[j];
                    curr = j;
                }
            }
            if (curr == -1) 
                    return -1;
            visited[curr] = true;
            for (unordered_set<int>::iterator it = edges[curr].begin(); it != edges[curr].end(); it++) {
                if (!visited[*it] && (T[*it] < 0 || T[*it] > t + length[curr][*it])) 
                    T[*it] = t+length[curr][*it];
            }            
        }
        int ans = 0;
        for (int i = 0; i < N; i++) 
            ans = max(T[i], ans);
        return ans;
    }
};












class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> edges(N);
        int E = times.size();
        for (int i = 0; i < E; i++)       
            edges[times[i][0]-1].push_back(pair<int, int>(times[i][1]-1, times[i][2]));
        vector<int> T(N, -1);
        vector<bool> visited(N, false);
        T[K-1] = 0;
        for (int i = 0; i < N; i++) {
            int t = INT_MAX;
            int curr = -1;
            for (int j = 0; j < N; j++) {
                if (!visited[j] && T[j] >= 0 && T[j] < t) {
                    t = T[j];
                    curr = j;
                }
            }
            if (curr == -1) 
                    return -1;
            visited[curr] = true;
            int n = edges[curr].size();
            for (int k = 0; k < n; k++) {
                if (!visited[edges[curr][k].first] && (T[edges[curr][k].first] < 0 || T[edges[curr][k].first] > t + edges[curr][k].second))
                    T[edges[curr][k].first] = t + edges[curr][k].second;
            }            
        }
        int ans = 0;
        for (int i = 0; i < N; i++) 
            ans = max(T[i], ans);
        return ans;
    }
};













//With priority_queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> edges(N);
        int E = times.size();
        for (int i = 0; i < E; i++)       
            edges[times[i][0]-1].push_back(pair<int, int>(times[i][1]-1, times[i][2]));
        vector<int> T(N, -1);
        vector<bool> visited(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(pair<int, int>(0, K-1));
        while (!pq.empty()) {
            int curr = pq.top().second;
            int t = pq.top().first;
            T[curr] = t;
            visited[curr] = true;
            int n = edges[curr].size();
            for (int i = 0; i < n; i++) {
                if (!visited[edges[curr][i].first])
                    pq.push(pair<int, int>(t + edges[curr][i].second, edges[curr][i].first));
            }
            while (!pq.empty() && visited[pq.top().second])
                pq.pop();
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (T[i] == -1)
                return -1;
            ans = max(T[i], ans);
        }
        return ans;
    }
};