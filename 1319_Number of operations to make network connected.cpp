class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n-1)
            return -1;
        int groups = 0;
        vector<bool> connected(n, false);
        vector<unordered_set<int>> link(n);
        for (int i = 0; i < m; i++) {
            link[connections[i][0]].insert(connections[i][1]);
            link[connections[i][1]].insert(connections[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (!connected[i])
                groups++;
            connect(i, link, connected);
        }
        return groups-1;
    }
    
    void connect(int i, vector<unordered_set<int>>& link, vector<bool>& connected) {
        if (connected[i])
            return;
        connected[i] = true;
        for (unordered_set<int>::iterator it = link[i].begin(); it != link[i].end(); it++)
            connect(*it, link, connected);
    }
};