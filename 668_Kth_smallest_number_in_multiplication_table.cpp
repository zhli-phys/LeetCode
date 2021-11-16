class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left < right) {
            int mid = (left + right) / 2;
            int rank = 0;
            for (int i = 1; i <= n; ++i)
                rank += min(m, mid / i);
            if (rank < k)
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
};