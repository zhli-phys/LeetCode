class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int total = accumulate(sweetness.begin(), sweetness.end(), 0);
        int n = sweetness.size();
        int left = 1;
        int right = total / (k + 1);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int curr = 0;
            int filled = 0;
            for (int i = 0; i < n; ++i) {
                curr += sweetness[i];
                if (curr >= mid) {
                    curr = 0;
                    ++filled;
                    if (filled == k + 1) 
                        break;
                }
            }
            if (filled >= k + 1) 
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};