class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        vector<vector<int>> ans;
        for (auto& interval : intervals) {
            if (interval[0] > currEnd) {
                ans.push_back({currStart, currEnd});
                currStart = interval[0];
                currEnd = interval[1];
            }
            else 
                currEnd = max(currEnd, interval[1]);
        }
        ans.push_back({currStart, currEnd});
        return ans;
    }
};















class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> sol;
        if (len > 0)
            sol.push_back(intervals[0]);
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] <= sol.back()[1]) 
                sol.back()[1] = max(intervals[i][1], sol.back()[1]);
            else
                sol.push_back(intervals[i]);
        }
        return sol;
    }
};