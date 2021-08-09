//dynamical programming; O(n) 68 ms 28%; O(n) 21.7 MB 41%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<ll> dp(n + 1, 1);
        if (s[0] == '*')
            dp[1] = 9;
        else if (s[0] == '0')
            dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            if (s[i-1] == '*') {
                dp[i] = dp[i-1] * 9;
                if (s[i-2] == '*')
                    dp[i] += dp[i-2] * 15;
                else if (s[i-2] == '1')
                    dp[i] += dp[i-2] * 9;
                else if (s[i-2] == '2')
                    dp[i] += dp[i-2] * 6;
                dp[i] %= M;
            }
            else if (s[i-1] == '0') {
                if (s[i-2] == '*')
                    dp[i] = (dp[i-2] * 2) % M;
                else if (s[i-2] == '1' || s[i-2] == '2')
                    dp[i] = dp[i-2];
                else
                    dp[i] = 0;
            }
            else if (s[i-1] > '0' && s[i-1] < '7') {
                if (s[i-2] == '*')
                    dp[i] = (dp[i-1] + dp[i-2] * 2) % M;
                else if (s[i-2] == '1' || s[i-2] == '2')
                    dp[i] = (dp[i-1] + dp[i-2]) % M;
                else
                    dp[i] = dp[i-1];
            }
            else {
                if (s[i-2] == '*' || s[i-2] == '1')
                    dp[i] = (dp[i-1] + dp[i-2]) % M;
                else
                    dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
};












//dynamical programming; O(n) 56 ms 38%; O(1) 11.6 MB 91%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        ll prev = 1;
        ll curr = 1;
        if (s[0] == '*')
            curr = 9;
        else if (s[0] == '0')
            curr = 0;
        for (int i = 2; i <= n; ++i) {
            ll temp;
            if (s[i-1] == '*') {
                temp = curr * 9;
                if (s[i-2] == '*')
                    temp += prev * 15;
                else if (s[i-2] == '1')
                    temp += prev * 9;
                else if (s[i-2] == '2')
                    temp += prev * 6;
                temp %= M;
            }
            else if (s[i-1] == '0') {
                if (s[i-2] == '*')
                    temp = (prev * 2) % M;
                else if (s[i-2] == '1' || s[i-2] == '2')
                    temp = prev;
                else
                    temp = 0;
            }
            else if (s[i-1] > '0' && s[i-1] < '7') {
                if (s[i-2] == '*')
                    temp = (curr + prev * 2) % M;
                else if (s[i-2] == '1' || s[i-2] == '2')
                    temp = (curr + prev) % M;
                else
                    temp = curr;
            }
            else {
                if (s[i-2] == '*' || s[i-2] == '1')
                    temp = (curr + prev) % M;
                else
                    temp = curr;
            }
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};