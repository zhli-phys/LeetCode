// Two pointer O(n^2)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = n - 1;
            for (int j = i + 1; j < n; ++j) {
                while (j < k && nums[i] + nums[j] + nums[k] >= target)
                    --k;
                if (j >= k)
                    break;
                ans += (k - j);
            }
        }
        return ans;
    }
};






// Binary search O(n^2 log(n))
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int currTarget = target - nums[i] - nums[j];
                auto it = lower_bound(nums.begin(), nums.end(), currTarget);
                ans += max(0, static_cast<int>(it - nums.begin()) - j - 1);
            }
        }
        return ans;
    }
};