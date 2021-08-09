class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (S > sum || S < -sum || (sum - S) % 2 == 1)
            return 0;
        if (S < 0)
            S = -S;
        int target = (sum - S) / 2;
        sort(nums.begin(), nums.end());
        vector<unordered_map<int, int>> hp(n);
        vector<int> sums(n);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        return helper(nums, target, n - 1, hp, sums);
    }
    
    int helper(vector<int>& nums, int target, int pos, vector<unordered_map<int, int>>& hp, vector<int>& sums) {
        if (pos < 0) {
            if (target == 0)
                return 1;
            else 
                return 0;
        }
        if (target < 0 || target > sums[pos])
            return 0;
        if (hp[pos].find(target) != hp[pos].end())
            return hp[pos][target];
        int ans = helper(nums, target, pos - 1, hp, sums) + helper(nums, target - nums[pos], pos - 1, hp, sums);
        hp[pos][target] = ans;
        return ans;
    }
};







class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (S > sum || S < -sum || (sum - S) % 2 == 1)
            return 0;
        if (S < 0)
            S = -S;
        int target = (sum - S) / 2;
        sort(nums.begin(), nums.end());
        vector<int> sums(n);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        return helper(nums, target, n - 1, sums);
    }
    
    int helper(vector<int>& nums, int target, int pos, vector<int>& sums) {
        if (pos < 0) {
            if (target == 0)
                return 1;
            else 
                return 0;
        }
        if (target < 0 || target > sums[pos])
            return 0;
        int ans = helper(nums, target, pos - 1, sums) + helper(nums, target - nums[pos], pos - 1, sums);
        return ans;
    }
};