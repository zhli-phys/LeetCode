using ll = long long;

class Solution {
public:
    int arrangeCoins(int n) {
        ll right = sqrt(2ll * n);
        ll left = 1;
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            if (mid * (mid + 1) / 2 <= n)
                left = mid;
            else
                right = mid - 1;
        }
        return right;
    }
};