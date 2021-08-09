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