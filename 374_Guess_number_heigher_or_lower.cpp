using ll = long long;

class Solution {
public:
    int guessNumber(int n) {
        ll left = 1;
        ll right = n;
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            if (guess(mid) < 0) 
                right = mid - 1;
            else 
                left = mid;
        }
        return left;
    }
};