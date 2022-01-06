class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> diff;
        for (auto& trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        int num = 0;
        for (auto& pass : diff) {
            num += pass.second;
            if (num > capacity)
                return false;
        }
        return true;
    }
};