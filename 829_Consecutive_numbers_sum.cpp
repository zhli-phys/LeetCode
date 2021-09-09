class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        while (n % 2 == 0)
            n /= 2;
        for (int i = 3; i <= sqrt(n); i += 2) {
            int curr = 0;
            while (n % i == 0) {
                n /= i;
                ++curr;
            }
            ans *= (curr + 1);
        }
        if (n != 1)
            ans *= 2;
        return ans;
    }
};