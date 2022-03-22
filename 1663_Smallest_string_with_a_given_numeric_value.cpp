class Solution {
public:
    string getSmallestString(int n, int k) {
        int m = (k - n) / 25;
        int r = (k - n) % 25;
        return m == n ? string(n, 'z') : string(n - m - 1, 'a') + static_cast<char>('a' + r) + string(m, 'z');
    }
};