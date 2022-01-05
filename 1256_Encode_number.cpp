class Solution {
public:
    string encode(int num) {
        int n = 1;
        while ((1 << n) - 1 <= num)
            ++n;
        --n;
        num -= (1 << n) - 1;
        string ans(n, '0');
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += (num % 2);
            num /= 2;
        }
        return ans;
    }
};