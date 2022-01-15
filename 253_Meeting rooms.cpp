class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) 
                pq.pop();
            pq.push(interval[1]);
            ans = max(ans, static_cast<int>(pq.size()));
        }
        return ans;
    }
};














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