class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int ref = abs(nums[i]) - 1;
            if (nums[ref] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[ref] = -nums[ref];
        }
        return ans;
    }
};











class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0 || nums[i] == i + 1)
                continue;
            int index = nums[i];
            nums[i] = -1;
            while (nums[index - 1] > 0 && nums[index - 1] != index) {
                int temp = nums[index - 1];
                nums[index - 1] = index;
                index = temp;
            }
            if (nums[index - 1] < 0)
                nums[index - 1] = index;
            else
                ans.push_back(index);
        }
        return ans;
    }
};