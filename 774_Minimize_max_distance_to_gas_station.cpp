class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size() - 1;
        vector<double> dist(n);
        for (int i = 0; i < n; ++i)
            dist[i] = stations[i+1] - stations[i];
        double left = 1e-6;
        double right = stations.back();
        while (right - left > 1e-6) {
            double mid = (right + left) / 2;
            long long curr = 0;
            for (int i = 0; i < n; ++i)
                curr += ceil(dist[i] / mid) - 1;
            if (curr > k)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};