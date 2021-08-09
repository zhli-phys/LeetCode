class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int num : nums1) 
            mp[num]++;
        vector<int> ans;
        for (int num : nums2) {
            if (mp.count(num)) {
                ans.push_back(num);
                mp[num]--;
                if (mp[num] == 0)
                    mp.erase(num);
            }
        }
        return ans;
    }
};