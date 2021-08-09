class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        stack<int> sk;
        for (int i = 0; i <= n; i++) {
            if (!sk.empty() && i + ranges[i] <= sk.top() + ranges[sk.top()])
                continue;
            while (!sk.empty() && i - ranges[i] <= sk.top() - ranges[sk.top()])
                sk.pop();
            sk.push(i);
        }
        int m = sk.size();
        vector<int> vec(m);
        for (int i = m-1; i >= 0; i--) {
            vec[i] = sk.top();
            sk.pop();
        }
        int ans = 0;
        int curr = 0;
        int idx = 0;
        while (curr < n) {
            while (idx < m && vec[idx] - ranges[vec[idx]] <= curr)
                idx++;
            idx--;
            if (idx < m && vec[idx] + ranges[vec[idx]] <= curr)
                return -1;
            ans++;
            curr = vec[idx] + ranges[vec[idx]];
            idx++;
        }
        return ans;
    }
};