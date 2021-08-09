//bitmask, 32 ms 97.49%, 16 MB 53.82%
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitmasks;
        for (auto&& word : words) {
            int bitmask = 0;
            for (char ch : word) 
                bitmask |= 1 << (ch - 'a');
            bitmasks.push_back(bitmask);
        }
        size_t n = words.size();
        int ans = 0;
        for (size_t i = 0; i < n; ++i) 
            for (size_t j = i + 1; j < n; ++j) 
                if ((bitmasks[i] & bitmasks[j]) == 0)
                    ans = max(ans, static_cast<int>(words[i].size() * words[j].size()));
        return ans;
    }
};










//bitmask + hashmap, 28 ms 98.81%, 16.3 MB 47.73%
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        for (auto&& word : words) {
            int bitmask = 0;
            for (char ch : word) 
                bitmask |= 1 << (ch - 'a');
            mp[bitmask] = max(mp[bitmask], static_cast<int>(word.size()));
        }
        int ans = 0;
        for (auto it1 = mp.begin(); it1 != mp.end(); ++it1) 
            for (auto it2 = it1; ++it2 != mp.end();) 
                if ((it1->first & it2->first) == 0)
                    ans = max(ans, it1->second * it2->second);
        return ans;
    }
};