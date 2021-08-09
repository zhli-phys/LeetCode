//8-12 ms
using ll = long long;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll sums = accumulate(nums.begin(), nums.end(), 0ll);
        ll curr = 0;
        ll moves = LLONG_MAX;
        ll n = nums.size();
        for (ll i = 0; i < n; ++i) {
            curr += nums[i];
            moves = min(moves, sums - 2 * curr - nums[i] * (n-2*i-2));
        }
        return moves;
    }
};








//8 ms
using ll = long long;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll moves = 0;
        ll i = 0;
        ll j = nums.size() - 1;
        while (i < j) {
            moves += (nums[j] - nums[i]);
            ++i;
            --j;
        }
        return moves;
    }
};

















//quick select, 430 ms
using ll = long long;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = quick_select(0, n, nums, n / 2);
        ll moves = 0;
        for (int num : nums)
            moves += (num > median ? num - median : median - num);
        return moves;
    }
    
    int quick_select(int i, int j, vector<int>& nums, int k) {
        if (j == i+1)
            return nums[i];
        int pivot = nums[i];
        int left = i + 1; 
        int right = j - 1;
        while (left <= right) {
            if (nums[left] < pivot)
                ++left;
            else if (nums[right] > pivot)
                --right;
            else {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        --left;
        swap(nums[i], nums[left]);
        if (left < k) 
            return quick_select(left + 1, j, nums, k);
        else if (left > k)
            return quick_select(i, left, nums, k);
        else 
            return nums[left];
    }
};















//better quick select, 24 ms
using ll = long long;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = quick_select(0, n, nums, n / 2);
        ll moves = 0;
        for (int num : nums)
            moves += (num > median ? num - median : median - num);
        return moves;
    }
    
    int quick_select(int i, int j, vector<int>& nums, int k) {
        if (j == i+1)
            return nums[i];
        int mid = (i+j) / 2;
        if (nums[i] > nums[mid])
            swap(nums[i], nums[mid]);
        if (nums[i] > nums[j-1]) 
            mid = i;
        else if (nums[mid] > nums[j-1])
            mid = j-1;
        swap(nums[i], nums[mid]);
        int pivot = nums[i];
        int left = i + 1; 
        int right = j - 1;
        while (left <= right) {
            if (nums[left] < pivot)
                ++left;
            else if (nums[right] > pivot)
                --right;
            else {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }
        --left;
        swap(nums[i], nums[left]);
        if (left < k) 
            return quick_select(left + 1, j, nums, k);
        else if (left > k)
            return quick_select(i, left, nums, k);
        else 
            return nums[left];
    }
};