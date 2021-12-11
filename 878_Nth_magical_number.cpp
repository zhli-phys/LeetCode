#define M 1000000007

using ll = long long;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int g = gdc(a, b);
        ll c = a / g * b;
        int step = (c / a) + (c / b) - 1;
        int m = n / step;
        int r = n % step;
        ll ans = m * c % M;
        int left = 0;
        int right = c - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int rank = mid / a + mid / b;
            if (rank < r) 
                left = mid + 1;
            else
                right = mid;
        }
        ans = (ans + left) % M;
        return ans;
    }
    
    int gdc(int a, int b) {
        if (a % b == 0)
            return b;
        return gdc(b, a % b);        
    }
};