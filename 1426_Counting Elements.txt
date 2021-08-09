class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto i : arr) 
            mp[i]++;
        int ans = 0;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (mp.count(it->first + 1))
                ans += mp[it->first];
        }
        return ans;
    }
};