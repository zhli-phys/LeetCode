class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> counts;
        counts[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (counts.find(sum - k) != counts.end())
                ans += counts[sum - k];
            if (counts.find(sum) != counts.end())
                counts[sum]++;
            else 
                counts[sum] = 1;
        }
        return ans;
    }
};