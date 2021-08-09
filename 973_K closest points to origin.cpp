class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double, int>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            if (pq.size() < K)
                pq.push(pair<double, int>(dist, i));
            else if (dist < pq.top().first) {
                pq.pop();
                pq.push(pair<double, int>(dist, i));
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double, int>> vec;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            vec.push_back(pair<double, int>(dist, i));
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) 
            ans.push_back(points[vec[i].second]);
        return ans;
    }
};