//binary search; O(n^2 log n) 528 ms 13%; O(1) 12.8 MB 21%
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int count = 0;
        while (start < n && nums[start] == 0)
            ++start;
        for (int i = start; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                count += (it - nums.begin() - j - 1);
            }
        }
        return count;
    }
};









//two pointers; O(n^2) 104 ms 61%; O(1) 12.7 MB 95%
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int count = 0;
        while (start < n && nums[start] == 0)
            ++start;
        for (int i = start; i < n - 2; ++i) {
            int j = i + 1;
            int k = j + 1;
            while (j < n - 1) {
                while (k < n && nums[i] + nums[j] > nums[k])
                    ++k;
                count += (k - j - 1);
                ++j;
            }
        }
        return count;
    }
};