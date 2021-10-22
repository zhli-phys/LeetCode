class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char ch : s)
            ++count[ch];
        vector<pair<int, char>> vec;
        for (auto it = count.begin(); it != count.end(); ++it)
            vec.push_back({it->second, it->first});
        sort(vec.begin(), vec.end(), greater<pair<int, char>>());
        string ans;
        for (auto& v : vec)
            ans += string(v.first, v.second);
        return ans;
    }
};