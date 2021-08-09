class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        int m = servers.size();
        int n = tasks.size();
        for (int i = 0; i < m; ++i) 
            available.push({servers[i], i});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waiting;
        int time = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            time = max(time, i);
            while (!waiting.empty() && waiting.top().first <= time) {
                available.push({servers[waiting.top().second], waiting.top().second});
                waiting.pop();
            }
            while (available.empty()) {
                time = waiting.top().first;
                while (!waiting.empty() && waiting.top().first <= time) {
                    available.push({servers[waiting.top().second], waiting.top().second});
                    waiting.pop();
                }
            }
            ans.push_back(available.top().second);
            waiting.push({time + tasks[i], available.top().second});
            available.pop();
        }
        return ans;
    }
};