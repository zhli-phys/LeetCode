//292 ms, 114.4 MB
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        size_t left = 0;
        size_t n = nums.size();
        unordered_set<int> mp;
        int max_sum = 0;
        int curr_sum = 0;
        for (size_t right = 0; right < n; ++right) {
            if (mp.find(nums[right]) == mp.end()) {
                mp.insert(nums[right]);
                curr_sum += nums[right];
                max_sum = max(max_sum, curr_sum);
            }
            else {
                while (nums[left] != nums[right]) {
                    mp.erase(nums[left]);
                    curr_sum -= nums[left];
                    ++left;
                }
                ++left;
                cout << left << endl;
            }
        }
        return max_sum;
    }
};







//136 ms, 89.3 MB, use vector instead of unordered_map
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        size_t left = 0;
        size_t n = nums.size();
        vector<bool> included(10001, false);
        int max_sum = 0;
        int curr_sum = 0;
        for (size_t right = 0; right < n; ++right) {
            if (!included[nums[right]]) {
                included[nums[right]] = true;
                curr_sum += nums[right];
                max_sum = max(max_sum, curr_sum);
            }
            else {
                while (nums[left] != nums[right]) {
                    included[nums[left]] = false;
                    curr_sum -= nums[left];
                    ++left;
                }
                ++left;
            }
        }
        return max_sum;
    }
};