#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int minNonZeroProduct(int p) {
        ll twoPMinusOne = 1ll << (p - 1);
        ll twoP = 1ll << p;
        return (((twoP - 1) % M) * power(twoP - 2, twoPMinusOne - 1)) % M;
    }
    
    ll power(ll a, ll n) {
        if (n == 0)
            return 1;
        ll half = power(a, n / 2);
        ll halfSquare = (half * half) % M;
        if (n % 2 == 0)
            return halfSquare;
        else
            return ((a % M) * halfSquare) % M;
    }
};