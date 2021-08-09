class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegrees(n);
        vector<int> outdegrees(n);
        return helper(0, n, requests, indegrees, outdegrees);
    }
    
    int helper(int idx, int n, vector<vector<int>>& requests, vector<int>& indegrees, vector<int>& outdegrees) {
        if (idx == requests.size()) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (indegrees[i] == outdegrees[i])
                    ans += indegrees[i];
                else
                    return 0;
            }
            return ans;
        }
        int ans1 = helper(idx+1, n, requests, indegrees, outdegrees);
        outdegrees[requests[idx][0]]++;
        indegrees[requests[idx][1]]++;
        int ans2 = helper(idx+1, n, requests, indegrees, outdegrees);
        outdegrees[requests[idx][0]]--;
        indegrees[requests[idx][1]]--;
        return max(ans1, ans2);
    }
};