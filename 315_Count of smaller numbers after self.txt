//Brute force: time limit exceeded
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (nums[i] > nums[j])
                    counts[i]++;
            }
        }
        return counts;
    }
};



//Divide and conquer
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        countSmaller(0, n, nums, counts);
        return counts;
    }
    
    void countSmaller(int left, int right, vector<int>& nums, vector<int>& counts) {
        if (left >= right - 1)
            return;
        int mid = (left + right) / 2;
        countSmaller(mid, right, nums, counts);
        sort(nums.begin()+mid, nums.begin()+right);
        for (int i = left; i < mid; i++) {
            vector<int>::iterator it = lower_bound(nums.begin()+mid, nums.begin()+right, nums[i]);
            counts[i] += (it - nums.begin() - mid);
        }
        countSmaller(left, mid, nums, counts);
    }
};







//Merger sort
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> vals(n);
        for (int i = 0; i < n; i++) {
            vals[i].first = nums[i];
            vals[i].second = i;
        }
        mergersort(0, n, vals, counts);
        return counts;
    }
    
    void mergersort(int left, int right, vector<pair<int, int>>& vals, vector<int>& counts) {
        if (left >= right - 1)
            return;
        int mid = (left + right) / 2;
        mergersort(left, mid, vals, counts);
        mergersort(mid, right, vals, counts);
        int i1 = left;
        int i2 = mid;
        vector<pair<int, int>> temp(right - left);
        for (int i = 0; i < right - left; i++) {
            if (i2 >= right || (i1 < mid && vals[i1].first <= vals[i2].first)) {
                temp[i] = vals[i1];
                counts[vals[i1].second] += (i2 - mid);
                i1++;
            }
            else if (i1 >= mid || vals[i1].first > vals[i2].first) {
                temp[i] = vals[i2];
                i2++;
            }
        }
        for (int i = left; i < right; i++)
            vals[i] = temp[i-left];
    }
};














//segment tree
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(80000);
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = range_sum(0, -10000, 10001, -10000, nums[i], counts);
            insert(0, -10000, 10001, nums[i], counts);
        }
        return ans;
    }
    
    void insert(int i, int left, int right, int num, vector<int>& counts) {
        if (left == right)
            return;
        if (num >= left && num < right) {
            ++counts[i];
            if (right == left + 1)
                return;
            int mid = (left + right) / 2;
            insert(2 * i + 1, left, mid, num, counts);
            insert(2 * i + 2, mid, right, num, counts);
        }
    }
    
    int range_sum(int i, int left, int right, int l, int r, vector<int>& counts) {
        if (left == right)
            return 0;
        if (left >= l && right <= r)
            return counts[i];
        else if (right <= l || left >= r)
            return 0;
        int mid = (left + right) / 2;
        return range_sum(2 * i + 1, left, mid, l, r, counts)
            + range_sum(2 * i + 2, mid, right, l, r, counts);
    }
};