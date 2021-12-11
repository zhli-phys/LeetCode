#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int numTilings(int n) {
        vector<ll>t0(n + 1);
        vector<ll>t1(n + 1);
        t0[0] = 1;
        t1[0] = 0;
        t0[1] = 1;
        t1[1] = 0;
        for (int i = 2; i <= n; ++i) {
            t0[i] = (t0[i-1] + t0[i-2] + 2 * t1[i-1]) % M;
            t1[i] = (t0[i-2] + t1[i-1]) % M;
        }
        return t0[n];
    }
};