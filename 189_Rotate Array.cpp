class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int g = gcf(k, n);
        for (int i = 0; i < g; i++) {
            int idx = i;
            int prev = nums[idx];
            while (true) {
                idx += k;
                idx %= n;
                int temp = nums[idx];
                nums[idx] = prev;
                prev = temp;
                if (idx == i)
                    break;
            }
        }
    }
    
    int gcf(int k, int n) {
        while(k != 0) {
            int temp = k;
            k = n % k;
            n = temp;
        }
        return n;
    }
};












class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; count < n; i++) {
            int idx = i;
            int prev = nums[idx];
            while (true) {
                idx += k;
                idx %= n;
                int temp = nums[idx];
                nums[idx] = prev;
                prev = temp;
                count++;
                if (idx == i)
                    break;
            }
        }
    }
};