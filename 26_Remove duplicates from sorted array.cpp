class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int pos = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[pos]) {
                nums[pos + 1] = nums[i];
                pos++;
            }
        }
        return pos + 1;
    }
};