class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int zero_pos = -1;
        int counts_of_zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                counts_of_zero++;
                if (counts_of_zero > 1)
                    break;
                zero_pos = i;
            }
            else
                product *= nums[i];
        }
        vector<int> ans(n, 0);
        if (counts_of_zero > 1) 
            return ans;
        else if (zero_pos > -1) {
            ans[zero_pos] = product;
            return ans;
        }
        else {
            for (int i = 0; i < n; i++) 
                ans[i] = product / nums[i];
            return ans;
        }
    }
};








class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int product = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = product;
            product *= nums[i];
        }
        int prev;
        product = 1;
        for (int i = n - 1; i >= 0; i--) {
            prev = nums[i];
            ans[i] *= product;
            product *= prev;
        }
        return ans;
    }
};