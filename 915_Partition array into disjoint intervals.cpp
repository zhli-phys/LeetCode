//O(n log n) 104 ms 5%; O(n) 31.6 MB 5%
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> left;
        map<int, int> right;
        for (int num : nums)
            ++right[num];
        for (int i = 1; i < n; ++i) {
            left.push(nums[i-1]);
            if (--right[nums[i-1]] == 0)
                right.erase(nums[i-1]);
            if (left.top() <= right.begin()->first)
                return i;
        }
        return -1;
    }
};










//O(n) 28 ms 72%; O(n) 21.7 MB 22%
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_max(n);
        left_max[0] = nums[0];
        for (int i = 1; i < n; ++i)
            left_max[i] = max(left_max[i-1], nums[i]);
        vector<int> right_min(n);
        right_min[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; --i) 
            right_min[i] = min(right_min[i+1], nums[i]);
        for (int i = 1; i < n; ++i) 
            if (left_max[i-1] <= right_min[i])
                return i;
        return -1;
    }
};