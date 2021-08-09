//sliding windwos; O(n) 52 ms 77%; O(1) 55.4 MB 22%
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int zeros = 0;
        while (left < n && right <= n) {
            if (left > right) {
                right = left;
                zeros = 0;
            }
            while (right < n && (zeros < k || nums[right] == 1)) {
                if (nums[right] == 0)
                    ++zeros;
                ++right;
            }
            maxlen = max(maxlen, right - left);
            if (nums[left] == 0)
                --zeros;
            ++left;
        }
        return maxlen;
    }
};








//Sliding windows; O(n) 60 ms 40%; O(1) 55.4 MB 22%
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxlen = 0;
        int zeros = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0)
                ++zeros;
            while (zeros > k) {
                if (nums[left] == 0)
                    --zeros;
                ++left;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};