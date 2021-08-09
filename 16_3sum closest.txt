//two pointers; O(n^2), 8 ms 80%; 9.9 MB 8%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int curr_sum = nums[i] + nums[left] + nums[right];
                if (curr_sum == target)
                    return target;
                else if (abs(curr_sum - target) < abs(closest_sum - target))
                    closest_sum = curr_sum;
                if (curr_sum > target)
                    --right;
                else
                    ++left;
            }
        }
        return closest_sum;
    }
};












//binary search, O(n^2 log n), 96 ms 8%; 9.8 MB 91%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int smaller_sum = INT_MIN;
        int larger_sum = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it_larger = lower_bound(nums.begin(), nums.end(), target - nums[i] - nums[j]);
                auto it_smaller = it_larger;
                --it_smaller;
                while (it_larger - nums.begin() == i || it_larger - nums.begin() == j)
                    ++it_larger;
                while (it_smaller - nums.begin() == i || it_smaller - nums.begin() == j)
                    --it_smaller;
                if (it_larger != nums.end())
                    larger_sum = min(larger_sum, nums[i] + nums[j] + *it_larger);
                if (it_smaller >= nums.begin())
                    smaller_sum = max(smaller_sum, nums[i] + nums[j] + *it_smaller);
            }
        }
        if (larger_sum == INT_MAX || smaller_sum != INT_MIN && target - smaller_sum < larger_sum - target)
            return smaller_sum;
        else
            return larger_sum;
    }
};












//binary search, O(n^2 log n), 28 ms 15%, 9.8 MB 56%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int smaller_sum = INT_MIN;
        int larger_sum = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it_larger = lower_bound(nums.begin(), nums.end(), target - nums[i] - nums[j]);
                auto it_smaller = it_larger;
                --it_smaller;
                while (it_larger - nums.begin() == i || it_larger - nums.begin() == j)
                    ++it_larger;
                while (it_smaller - nums.begin() == i || it_smaller - nums.begin() == j)
                    --it_smaller;
                if (it_larger != nums.end())
                    larger_sum = min(larger_sum, nums[i] + nums[j] + *it_larger);
                if (it_smaller >= nums.begin())
                    smaller_sum = max(smaller_sum, nums[i] + nums[j] + *it_smaller);
                if (larger_sum == target || smaller_sum == target)
                    return target;
            }
        }
        if (larger_sum == INT_MAX || smaller_sum != INT_MIN && target - smaller_sum < larger_sum - target)
            return smaller_sum;
        else
            return larger_sum;
    }
};