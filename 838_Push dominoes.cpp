//O(n) 52 ms 15%; O(n) 22.7 MB 5%
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int dist = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R')
                dist = 0;
            else if (dominoes[i] == 'L')
                dist = -1;
            if (dist >= 0) {
                right[i] = dist;
                ++dist;
            }
        }
        dist = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L')
                dist = 0;
            else if (dominoes[i] == 'R')
                dist = -1;
            if (dist >= 0) {
                left[i] = dist;
                ++dist;
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            if (left[i] == -1 && right[i] == -1)
                ans += '.';
            else if (left[i] == -1)
                ans += 'R';
            else if (right[i] == -1)
                ans += 'L';
            else {
                if (left[i] < right[i])
                    ans += 'L';
                else if (left[i] > right[i])
                    ans += 'R';
                else
                    ans += '.';
            }
        }
        return ans;
    }
};














//O(n) 44 ms 19%; O(n) 17.6MB 6%
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n);
        int f = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R')
                f = n;
            else if (dominoes[i] == 'L')
                f = 0;
            force[i] = f;
            if (f > 0)
                --f;
        }
        f = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L')
                f = n;
            else if (dominoes[i] == 'R')
                f = 0;
            force[i] -= f;
            if (f > 0)
                --f;
        }
        string ans(n, '.');
        for (int i = 0; i < n; ++i) {
            if (force[i] > 0)
                ans[i] = 'R';
            else if (force[i] < 0)
                ans[i] = 'L';
        }
        return ans;
    }
};