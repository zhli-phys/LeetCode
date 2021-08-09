//O(n log n) 12 ms 76%; O(n) 10.4 MB 60%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int num : nums) {
            auto it = lower_bound(seq.begin(), seq.end(), num);
            if (it == seq.end())
                seq.push_back(num);
            else
                *it = num;
        }
        return seq.size();
    }
};








//dynamical programming; O(n^2) 380 ms 11%; O(n) 10.6 MB 35%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};












class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ll(n, -1);
        vector<vector<int>> llbw(n, ll);
        return lengthbw(nums, 0, 0, llbw);
    }
   
    int lengthbw(vector<int>& nums, int pos, int bw, vector<vector<int>>& llbw) {
        if (pos >= nums.size() || bw > pos)
            return 0;
        if (llbw[pos][bw] > 0)
            return llbw[pos][bw];
        int ans;
        if (bw == pos) {
            int next = lengthbw(nums, pos + 1, pos + 1, llbw);
            int curr = lengthbw(nums, pos + 1, pos, llbw) + 1;
            ans = max(next, curr);
        }
        else if (nums[pos] <= nums[bw])
            ans = lengthbw(nums, pos + 1, bw, llbw);
        else {
            int next = lengthbw(nums, pos + 1, bw, llbw);
            int curr = 1 + lengthbw(nums, pos + 1, pos, llbw);
            ans = max(next, curr);
        }
        llbw[pos][bw] = ans;
        return ans;
    }
};







class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> ll(n, -1);
        vector<vector<int>> llbw(n, ll);
        llbw[n - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[n - 1] <= nums[i])
                llbw[n - 1][i] = 0;
            else
                llbw[n - 1][i] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            llbw[i][i] = max(llbw[i + 1][i + 1], llbw[i + 1][i] + 1);
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] <= nums[j])
                    llbw[i][j] = llbw[i + 1][j];
                else
                    llbw[i][j] = max(llbw[i + 1][j], llbw[i + 1][i] + 1);
            }
        }
        return llbw[0][0];
    }
};














class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> ll(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j] && ll[j] + 1 > ll[i])
                    ll[i] = ll[j] + 1;
            }
        }
        return *max_element(ll.begin(), ll.end());
    }
};








class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp;
        int len = 0;
        for (int i = 0; i < n; i++) {
            int pos = search_index(dp, nums[i]);
            if (pos < 0)
                pos = -(pos + 1);
            if (pos == dp.size()) 
                dp.push_back(nums[i]);
            else
                dp[pos] = nums[i];
        }
        return dp.size();
    }
    
    int search_index(vector<int>& dp, int target) {
        int len = dp.size();
        int left = 0;
        int right = len;
        while (left < right) {
            int middle = (left + right) / 2;
            if (dp[middle] == target)
                return middle;
            else if (dp[middle] < target) 
                left = middle + 1;
            else 
                right = middle;
        }
        return -left - 1;
    }
};