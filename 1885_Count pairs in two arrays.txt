//sort + binary search; 188 ms 90%; 93 MB 90%
using ll = long long;

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for (int i = 0; i < n; ++i)
            nums1[i] -= nums2[i];
        sort(nums1.begin(), nums1.end());
        ll ans = 0;
        auto it_positive = upper_bound(nums1.begin(), nums1.end(), 0);
        ll count_positive = nums1.end() - it_positive;
        ans += count_positive * (count_positive - 1) / 2;
        for (auto it = nums1.begin(); it != it_positive; ++it) {
            auto it_j = lower_bound(it_positive, nums1.end(), 1 - *it);
            ans += nums1.end() - it_j;
        }
        return ans;
    }
};












//sort + two iterators; O(n log n) 288 ms 55%; 93.1 MB 74%
using ll = long long;

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for (int i = 0; i < n; ++i)
            nums1[i] -= nums2[i];
        sort(nums1.begin(), nums1.end());
        ll ans = 0;
        auto it_positive = upper_bound(nums1.begin(), nums1.end(), 0);
        ll count_positive = nums1.end() - it_positive;
        ans += count_positive * (count_positive - 1) / 2;
        for (auto it_i = nums1.begin(), it_j = nums1.end() - 1; it_i != it_positive; ++it_i) {
            while (*it_i + *it_j > 0)
                --it_j;
            ans += nums1.end() - it_j - 1;
        }
        return ans;
    }
};