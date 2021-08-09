class Solution {
public:
    int divide(int dividend, int divisor) {
        long dividend_long = dividend;
        long divisor_long = divisor;
        bool neg = false;
        if (dividend_long < 0) {
            dividend_long = - dividend_long;
            neg = !neg;
        }
        if (divisor_long < 0) {
            divisor_long = - divisor_long;
            neg = !neg;
        }
        long ans = 0;
        while (dividend_long >= divisor_long) {
            for (int i = 0; i <= 32; i++) {
                if ((divisor_long << (i + 1)) > dividend_long) {
                    dividend_long -= (divisor_long << i);
                    ans += (1l << i);
                    break;
                }
            }
        }
        if (neg)
            ans = -ans;
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return ans;
    }
};