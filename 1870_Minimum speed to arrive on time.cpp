//340 ms
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > hour + 1)
            return -1;
        return search(1, 10000000, dist, hour);
    }
    
    int search(int left, int right, vector<int>& dist, double hour) {
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        double time = 0;
        size_t n = dist.size() - 1;
        for (size_t i = 0; i < n; ++i) 
            time += dist[i] / mid + (dist[i] % mid ? 1 : 0);
        time += static_cast<double>(dist[n]) / static_cast<double>(mid);
        if (time <= hour)
            return search(left, mid, dist, hour);
        else
            return search(mid + 1, right, dist, hour);
    }
};







//340 ms
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > hour + 1)
            return -1;
        int left = 1;
        int right = 1e7;
        while (left < right) {
            int mid = (left + right) / 2;
            double time = 0;
            size_t n = dist.size() - 1;
            for (size_t i = 0; i < n; ++i) 
                time += dist[i] / mid + (dist[i] % mid ? 1 : 0);
            time += static_cast<double>(dist[n]) / static_cast<double>(mid);
            if (time <= hour)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};








//220 ms, use the ceil function
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > hour + 1)
            return -1;
        int left = 1;
        int right = 1e7;
        while (left < right) {
            int mid = (left + right) / 2;
            double time = 0;
            size_t n = dist.size() - 1;
            for (size_t i = 0; i < n; ++i) 
                time += ceil(static_cast<double>(dist[i]) / mid);
            time += static_cast<double>(dist[n]) / mid;
            if (time <= hour)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};