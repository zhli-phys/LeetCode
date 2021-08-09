//100 ms 32%; 36.9 MB 44%
#define M 1000000007
using ll = long long;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i)
            vec.push_back({efficiency[i], speed[i]});
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        ll curr_total_speed = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll max_performance = INT_MIN;
        for (int i = 0; i < k; ++i) {
            pq.push(vec[i].second);
            curr_total_speed += vec[i].second;
            max_performance = max(max_performance, curr_total_speed * vec[i].first);
        }
        for (int i = k; i < n; ++i) {
            pq.push(vec[i].second);
            curr_total_speed += vec[i].second;
            curr_total_speed -= pq.top();
            pq.pop();
            max_performance = max(max_performance, curr_total_speed * vec[i].first);
        }
        return max_performance % M;
    }
};













//shorter code; 144 ms 13%; 36.8 MB 68%
#define M 1000000007
using ll = long long;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i)
            vec.push_back({efficiency[i], speed[i]});
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        ll curr_total_speed = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll max_performance = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pq.push(vec[i].second);
            curr_total_speed += vec[i].second;
            if (pq.size() > k) {
                curr_total_speed -= pq.top();
                pq.pop();
            }
            max_performance = max(max_performance, curr_total_speed * vec[i].first);
        }
        return max_performance % M;
    }
};