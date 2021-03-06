class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        int two = n - 1;
        while (one <= two) {
            if (nums[one] == 0) {
                swap(nums[one], nums[zero]);
                ++zero;
                ++one;
            }
            else if (nums[one] == 2) {
                swap(nums[one], nums[two]);
                --two;
            }
            else
                ++one;
        }
    }
};














class Solution {
public:
    void sortColors(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        while (right >= 0 && nums[right] == 2) 
            right--;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                if (left < i) {
                    nums[left] = 0;
                    nums[i] = 1;
                }
                left++;
            }
            else {
                if (nums[i] == 2) {
                    nums[i] = nums[right];
                    nums[right] = 2;
                    while (right >= 0 && nums[right] == 2)
                        right--;
                    if (nums[i] == 0) {
                        if (left < i) {
                            nums[left] = 0;
                            nums[i] = 1;
                        }
                        left++;
                    }
                }
            }
        }
    }
};