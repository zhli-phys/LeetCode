class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int len = 0;
        while (maxNum > 0) {
            ++len;
            maxNum >>= 1;
        }
        int maxPre = 0;
        for (int i = len - 1; i >= 0; --i) {
            unordered_set<int> prefix;
            for (int num : nums)
                prefix.insert(num >> i);
            maxPre = (maxPre << 1) + 1;
            bool found = false;
            for (int pre : prefix) {
                if (prefix.find(pre ^ maxPre) != prefix.end()) {
                    found = true;
                    break;
                }
            }
            if (!found)
                --maxPre;
        }
        return maxPre;
    }
};