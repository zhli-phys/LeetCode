class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> combine(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            combine[i][0] = endTime[i];
            combine[i][1] = startTime[i];
            combine[i][2] = profit[i];
        }
        sort(combine.begin(), combine.end());
        map<int, int> dp;
        int prevProf = 0;
        for (int i = 0; i < n; ++i) {
            int currProf = max(prevProf, dp[combine[i][0]]);
            auto it = dp.lower_bound(combine[i][1]);
            if (it->first == combine[i][1]) {
                currProf = max(currProf, it->second + combine[i][2]);
            }
            else if (it != dp.begin()) {
                --it;
                currProf = max(currProf, it->second + combine[i][2]);
            }
            else {
                currProf = max(currProf, combine[i][2]);
            }
            prevProf = currProf;
            dp[combine[i][0]] = currProf;
        }
        return prevProf;
    }
};