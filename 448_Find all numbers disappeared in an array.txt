class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = nums[i] - 1;
            while (nums[j] != (j + 1)) {
                int temp = nums[j] - 1;
                nums[j] = j + 1;
                j = temp;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                ans.push_back(i + 1);
        }
        return ans;
    }
};