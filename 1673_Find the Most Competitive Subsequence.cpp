class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int right = n - k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i <= right; i++) 
            pq.push({nums[i], i});
        vector<int> ans;
        int currpos = 0;
        while (ans.size() < k) {
            auto&& p = pq.top();
            if (p.second >= currpos) {
                ans.push_back(p.first);
                currpos = p.second;
                pq.pop();
                right++;
                if (right < n) 
                    pq.push({nums[right], right});                
            }
            else
                pq.pop();
        }
        return ans;
    }
};














class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.size() + n - i > k && dq.front() > nums[i])
                dq.pop_front();
            dq.push_front(nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(dq.back());
            dq.pop_back();
        }
        return ans;
    }
};