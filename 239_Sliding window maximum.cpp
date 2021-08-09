class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_front(0);
        for (int i = 1; i < k - 1; i++) {
            while (!dq.empty() && nums[dq.front()] <= nums[i])
                dq.pop_front();
            dq.push_front(i);
        }
        vector<int> ans;
        for (int i = k - 1; i < nums.size(); i++) {
            if (i - dq.back() >= k)
                dq.pop_back();
            while (!dq.empty() && nums[dq.front()] <= nums[i])
                dq.pop_front();
            dq.push_front(i);
            ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};