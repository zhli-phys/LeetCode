class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> pos(26, pair<int, int>(-1, 0));
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (pos[s[i] - 'a'].second == 0) 
                pos[s[i] - 'a'].first = i;
            pos[s[i] - 'a'].second++;
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (pos[i].second == 1 && (ans < 0 || pos[i].first < ans))
                ans = pos[i].first;
        }
        return ans;
    }
};