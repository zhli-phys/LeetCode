class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> rank(26, -1);
        int n = order.size();
        for (int i = 0; i < n; ++i)
            rank[order[i]-'a'] = i;
        vector<int> count(26);
        for (auto ch : str)
            if (rank[ch-'a'] >= 0)
                ++count[ch-'a'];
        int rk = 0;
        for (auto& ch : str) {
            if (rank[ch-'a'] >= 0) {
                while (rk < rank.size() && count[order[rk]-'a'] == 0)
                    ++rk;
                ch = order[rk];
                --count[order[rk]-'a'];
            }
        }
        return str;
    }
};