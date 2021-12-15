class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int ans = 0;
        int preMin = arrays[0].front();
        int preMax = arrays[0].back();
        for (int i = 1; i < m; ++i) {
            ans = max(ans, abs(arrays[i].back() - preMin));
            ans = max(ans, abs(preMax - arrays[i].front()));
            preMin = min(preMin, arrays[i].front());
            preMax = max(preMax, arrays[i].back());
        }
        return ans;
    }
};