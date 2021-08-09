//next letter pointer; O(n + k) 912 ms 6%; O(n) 387.4 MB 5%
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> next_pos(n + 1, vector<int>(26, -2));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j)
                next_pos[i][j] = next_pos[i+1][j];
            next_pos[i][s[i]-'a'] = i;
        }
        int count = 0;
        for (auto& word : words) {
            int pos = 0;
            int flag = true;
            for (char ch : word) {
                pos = next_pos[pos][ch-'a'] + 1;
                if (pos < 0) {
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};






//binary search; O(n + k log n) 180 ms 65%; O(n) 48.1 MB 64%
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> position(26, vector<int>());
        for (int i = 0; i < n; ++i)
            position[s[i]-'a'].push_back(i);
        int count = 0;
        for (auto& word : words) {
            int pos = 0;
            int flag = true;
            for (char ch : word) {
                auto& curr = position[ch-'a'];
                auto it = lower_bound(curr.begin(), curr.end(), pos);
                if (it == curr.end()) {
                    flag = false;
                    break;
                }
                pos = *it + 1;
            }
            count += flag;
        }
        return count;
    }
};