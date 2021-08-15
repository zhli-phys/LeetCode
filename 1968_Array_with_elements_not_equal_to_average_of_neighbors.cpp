class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        while (left <= right) {
            ans.push_back(nums[left]);
            ++left;
            if (left <= right) {
                ans.push_back(nums[right]);
                --right;
            }
        }
        return ans;
    }
};










class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(nums);
        for (int i = 0; i < n - 1; i += 2) {
            swap(ans[i], ans[i+1]);
        }
        return ans;
    }
};