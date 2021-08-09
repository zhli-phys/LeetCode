//binary search; 40 ms 71%; 31.8 MB 41%
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int left = it - arr.begin();
        int right = left + 1;
        if (left == n || (left > 0 && x - arr[left-1] <= arr[left] - x)) {
            --left;
            --right;
        }
        --k;
        while (k > 0) {
            if (right >= n || (left > 0 && x - arr[left-1] <= arr[right] - x))
                --left;
            else
                ++right;
            --k;
        }
        vector<int> ans;
        for (int i = left; i < right; ++i)
            ans.push_back(arr[i]);
        return ans;
    }
};