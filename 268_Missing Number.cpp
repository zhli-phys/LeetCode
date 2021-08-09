class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> presence(n+1, false);
        for (auto num : nums)
            presence[num] = true;
        for (int i = 0; i <= n; i++) {
            if (!presence[i])
                return i;
        }
        return -1;
    }
};









class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums)
            sum += num;
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};