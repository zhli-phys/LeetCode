//use stack to save gaps; O(n) 40 ms 36%; O(n) 32.6 MB 15%
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        int last = -1;
        stack<int> gaps;
        int ans = 0;
        while (curr < n) {
            if (nums[curr] >= left && nums[curr] <= right) {
                gaps.push(curr - last - 1);
                last = curr;
            }
            else if (nums[curr] > right) {
                gaps.push(curr - last - 1);
                ans += (curr - prev - 1) * (curr - prev) / 2;
                while (!gaps.empty()) {
                    ans -= gaps.top() * (gaps.top() + 1) / 2;
                    gaps.pop();
                }
                prev = curr;
                last = curr;
            }
            ++curr;
        }
        gaps.push(curr - last - 1);
        ans += (curr - prev - 1) * (curr - prev) / 2;
        while (!gaps.empty()) {
            ans -= gaps.top() * (gaps.top() + 1) / 2;
            gaps.pop();
        }
        return ans;
    }
};












//O(n) 36 ms 56%; O(1) 32.5 MB 15%
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int prev = -1;
        int curr = 0;
        int last = -1;
        int ans = 0;
        while (curr < n) {
            if (nums[curr] >= left && nums[curr] <= right) {
                ans -= (curr - last - 1) * (curr - last) / 2;
                last = curr;
            }
            else if (nums[curr] > right) {
                ans += (curr - prev - 1) * (curr - prev) / 2 - (curr - last - 1) * (curr - last) / 2;
                prev = curr;
                last = curr;
            }
            ++curr;
        }
        ans += (curr - prev - 1) * (curr - prev) / 2 - (curr - last - 1) * (curr - last) / 2;
        return ans;
    }
};