class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        if (i == n) {
            ans.push_back(newInterval);
            return ans;
        }
        vector<int> mid(2);
        mid[0] = min(newInterval[0], intervals[i][0]);
        mid[1] = newInterval[1];
        while (i < n && intervals[i][1] < newInterval[1]) {
            i++;
        }
        if (i == n) {
            ans.push_back(mid);
            return ans;
        }
        else {
            if (intervals[i][0] <= newInterval[1]) {
                mid[1] = intervals[i][1];
                ans.push_back(mid);
            }
            else {
                ans.push_back(mid);
                ans.push_back(intervals[i]);
            }
            i++;
            while (i < n) {
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
        }
    }
};