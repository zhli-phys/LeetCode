class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ingoing(n+1);
        vector<int> outgoing(n+1);
        for (auto& edge : trust) {
            ++ingoing[edge[1]];
            ++outgoing[edge[0]];
        }
        for (int i = 1; i <= n; ++i)
            if (ingoing[i] == n - 1 && outgoing[i] == 0)
                return i;
        return -1;
    }
};