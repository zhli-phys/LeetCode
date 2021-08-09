class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int sol = 0;
        queue<int> zeros;
        queue<int> negatives;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0)
                zeros.push(i);
            else if (nums[i] < 0)
                negatives.push(i);
        }
        zeros.push(len);
        int left = 0;
        while (!zeros.empty()) {
            int right = zeros.front();
            zeros.pop();
            if (left == right) {
                left = right + 1;
                continue;
            }
            int counts = 0;
            int first, last;
            if (!negatives.empty() && negatives.front() < right) {
                first = negatives.front();
                last = negatives.front();
                negatives.pop();
                counts++;
            }
            while (!negatives.empty() && negatives.front() < right) {
                last = negatives.front();
                negatives.pop();
                counts++;
            }
            if (counts % 2 == 0) {
                int product = nums[left];
                for (int i = left + 1; i < right; i++)
                    product *= nums[i];
                if (product > sol)
                    sol = product;
            }
            else {
                int product = nums[left];
                for (int i = left + 1; i < last; i++)
                    product *= nums[i];
                if (first < len - 1) {
                    int product_right = nums[first + 1];
                    for (int i = first + 2; i < right; i++)
                        product_right *= nums[i];
                    if (product_right > product)
                        product = product_right;
                }
                if (product > sol)
                    sol = product;
            }
            left = right + 1;
        }
        return sol;
    }
};



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int premax = nums[0];
        int premin = nums[0];
        int sol = premax;
        for (int i = 1; i < nums.size(); i++) {
            int current_max = max(premax * nums[i], premin * nums[i]);
            int current_min = min(premax * nums[i], premin * nums[i]);
            premax = max(current_max, nums[i]);
            premin = min(current_min, nums[i]);
            sol = max(sol, premax);
        }
        return sol;
    }
};