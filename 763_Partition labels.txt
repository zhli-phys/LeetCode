class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<pair<int, int>> pos(26, pair<int, int>(-1, -1));
        int n = S.size();
        for (int i = 0; i < n; i++) {
            int letter = S[i] - 97;
            if (pos[letter].first < 0)
                pos[letter].first = i;
            if (pos[letter].second < i)
                pos[letter].second = i;
        }
        sort(pos.begin(), pos.end());
        int start = 0;
        int end = 0;
        for (int i = 0; i < 26; i++) {
            if (pos[i].first > end && end >= 0) {
                ans.push_back(end - start + 1);
                start = pos[i].first;
            }
            if (pos[i].second > end)
                end = pos[i].second;
        }
        ans.push_back(n - start);
        return ans;
    }
};