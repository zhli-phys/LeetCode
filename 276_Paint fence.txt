class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1)
            return k;
        int same = k;
        int diff = k * (k - 1);
        for (int i = 2; i < n; ++i) {
            int prev_same = same;
            int prev_diff = diff;
            same = prev_diff;
            diff = (prev_diff + prev_same) * (k - 1);
        }
        return same + diff;
    }
};