class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        unordered_map<int, int> pos;
        pos[0] = -1;
        for (int i = 0; i < n; ++i) {
            curr += 2 * nums[i] - 1;
            if (pos.find(curr) != pos.end())
                ans = max(ans, i - pos[curr]);
            else
                pos[curr] = i;
        }
        return ans;
    }
};