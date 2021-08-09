class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endtimes;
        int ans = 1;
        for (int i = 0; i < intervals.size(); i++) {
            while (!endtimes.empty() && endtimes.top() <= intervals[i][0]) 
                endtimes.pop();
            endtimes.push(intervals[i][1]);
            if (endtimes.size() > ans)
                ans = endtimes.size();
        }
        return ans;
    }
};