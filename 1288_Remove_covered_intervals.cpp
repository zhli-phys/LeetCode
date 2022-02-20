class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), mySmaller);
        int currEnd = INT_MIN;
        int ans = 0;
        for (auto& interval : intervals) {
            if (interval[1] > currEnd) {
                ++ans;
                currEnd = interval[1];
            }
        }
        return ans;
    }
    
    static bool mySmaller(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
};












class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int> b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                else
                    return a[0] < b[0];
            });
        int currEnd = INT_MIN;
        int ans = 0;
        for (auto& interval : intervals) {
            if (interval[1] > currEnd) {
                ++ans;
                currEnd = interval[1];
            }
        }
        return ans;
    }
};