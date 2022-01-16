class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int left = -1;
        int right = 0;
        while (right < n && seats[right] == 0) 
            ++right;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                left = i;
                ++right;
                while (right < n && seats[right] == 0)
                    ++right;
            }
            else {
                int curr = INT_MAX;
                if (left >= 0)
                    curr = min(curr, i - left);
                if (right < n)
                    curr = min(curr, right - i);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};















class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> dist(n);
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1)
                prev = i;
            else if (prev >= 0)
                dist[i] = i - prev;
            else 
                dist[i] = INT_MAX;
        }
        prev = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1)
                prev = i;
            else if (prev >= 0)
                dist[i] = min(dist[i], prev - i);
        }
        return *max_element(dist.begin(), dist.end());
    }
};