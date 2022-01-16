class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int currMax = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, arr[i]);
            if (currMax <= i)
                ++ans;
        }
        return ans;
    }
};