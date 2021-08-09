class Solution {
public:
    int reverse(int x) {
        queue<int> q;
        bool neg = false;
        long x1 = x;
        if (x < 0) {
            neg = true;
            x1 = 0 - (long) x;
        }
        while (x1) {
            q.push(x1 % 10);
            x1 /= 10;
        }
        long ans = 0;
        while (!q.empty()) {
            ans = 10 * ans + q.front();
            q.pop();
        }
        if (ans > pow(2, 31))
            return 0;
        if (neg)
            ans = -ans;
        return ans;
    }
};