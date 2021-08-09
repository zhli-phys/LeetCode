\\Time limit exceeded
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = n-1; i>= 0; i--) {
            dp[i] = nums[i];
            int temp = 0;
            for (int j = 1; j <= k; j++) {
                if (i+j >= n)
                    break;
                temp = max(temp, dp[i+j]);
            }
            dp[i] += temp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};





class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> dp(n);
        for (int i = n-1; i>= 0; i--) {
            dp[i] = nums[i];
            if (!deq.empty() && deq.front() - i > k)
                deq.pop_front();
            int temp = 0;
            if (!deq.empty())
                temp = max(temp, dp[deq.front()]);
            dp[i] += temp;
            while (!deq.empty() && dp[deq.back()] <= dp[i])
                deq.pop_back();
            deq.push_back(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};