class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return true;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        sort(nums.begin(), nums.end());
        sum -= nums[n - 1];
        vector<unordered_set<int>> bad(n);
        return findsum(nums, n - 2, sum, bad);
    }
    
    bool findsum(vector<int>& nums, int right, int sum, vector<unordered_set<int>>& bad) {
        if (sum < 0)
            return false;
        if (sum == 0)
            return true;
        if (right < 0)
            return false;
        if (bad[right].find(sum) != bad[right].end())
            return false;
        bool found = false;
        for (int j = right; j >= 0; j--) {
            if (findsum(nums, j - 1, sum - nums[j], bad))
                return true;
        }
        bad[right].insert(sum);
        return false;
    }
};