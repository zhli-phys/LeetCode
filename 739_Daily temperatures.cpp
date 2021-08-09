class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> sk;
        int n = T.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!sk.empty() && T[sk.top()] < T[i]) {
                ans[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return ans;
    }
};