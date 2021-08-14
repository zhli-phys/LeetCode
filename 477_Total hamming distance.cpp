class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> ones(32);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                ones[i] += (num % 2);
                num /= 2;
            }
        }
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 32; ++i)
            ans += ones[i] * (n - ones[i]);
        return ans;
    }
};