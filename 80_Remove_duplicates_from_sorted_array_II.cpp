class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int index = 1;
        int count = 1;
        int curr = nums[0];;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == curr) {
                if (count < 2) {
                    ++count;
                    nums[index] = nums[i];
                    ++index;
                }
            }
            else {
                nums[index] = nums[i];
                ++index;
                curr = nums[i];
                count = 1;
            }
        }
        return index;
    }
};