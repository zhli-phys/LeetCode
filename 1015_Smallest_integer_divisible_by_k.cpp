class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r = 0;
        for (int i = 1; i <= k; ++i) {
            r = (10 * r + 1) % k;
            if (r == 0)
                return i;
        }
        return -1;
    }
};














class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int M = 9 * k;
        int r = 1;
        for (int i = 1; i <= M; ++i) {
            r = 10 * r % M;
            if (r == 1)
                return i;
        }
        return -1;
    }
};










class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int M = 9 * k;
        unordered_set<int> seen;
        int r = 1;
        for (int i = 1; i <= M; ++i) {
            r = 10 * r % M;
            if (r == 1)
                return i;
            if (seen.find(r) != seen.end())
                return -1;
            seen.insert(r);
        }
        return -1;
    }
};