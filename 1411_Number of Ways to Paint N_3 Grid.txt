#define M 1000000007

class Solution {
public:
    int numOfWays(int n) {
        long a = 1;
        long b = 1;
        for (int i = 1; i < n; i++) {
            int temp = a;
            a = (3 * a + 2 * b) % M;
            b = (2 * temp + 2 * b) % M;
        }
        return (6 * a + 6 * b) % M;
    }
};