class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k == 0) {
            unordered_map<int, int> mp;
            for (int num : nums)
                ++mp[num];
            int ans = 0;
            for (auto it = mp.begin(); it != mp.end(); ++it)
                ans += (it->second >= 2);
            return ans;
        }
        else {
            unordered_set<int> st;
            for (int num : nums) 
                st.insert(num);
            int ans = 0;
            for (int num : st) 
                ans += st.count(num + k);
            return ans;
        }
    }
};