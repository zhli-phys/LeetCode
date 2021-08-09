class Solution {
public:
    bool isArmstrong(int n) {
        int m = n;
        int k = 0;
        while (m > 0) {
            ++k;
            m /= 10;
        }
        m = n;
        int sum = 0;
        while (m > 0) {
            sum += static_cast<int>(pow(m % 10, k) + 0.5);
            m /= 10;
        }
        return sum == n;
    }
};