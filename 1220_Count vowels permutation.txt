//O(n) 12 ms 71%; O(1) 6 MB 88%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<ll> prev(5, 1);
        vector<ll> curr(5, 1);
        for (int i = 1; i < n; ++i) {
            curr[0] = prev[1];
            curr[1] = (prev[0] + prev[2]) % M;
            curr[2] = (prev[0] + prev[1] + prev[3] + prev[4]) % M;
            curr[3] = (prev[2] + prev[4]) % M;
            curr[4] = prev[0];
            for (int j = 0; j < 5; ++j)
                prev[j] = curr[j];
        }
        return accumulate(curr.begin(), curr.end(), 0ll) % M;
    }
};