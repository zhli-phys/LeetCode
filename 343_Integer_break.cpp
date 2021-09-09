class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int ans = 1;
        if (n % 3 == 1) {
            ans = 4;
            n -= 4;
        }
        else if (n % 3 == 2) {
            ans = 2;
            n -= 2;
        }
        while (n > 0) {
            ans *= 3;
            n -= 3;
        }
        return ans;
    }
};