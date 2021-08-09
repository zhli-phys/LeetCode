class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        unordered_map<int, int> mp;
        int n = nums.size() / 2;
        vector<int> mins;
        vector<int> maxs;
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int b = nums[2 * n - 1 - i];
            mp[a + b]++;
            mins.push_back(min(a, b) + 1);
            maxs.push_back(max(a, b) + limit);
        }
        sort(mins.begin(), mins.end());
        sort(maxs.begin(), maxs.end(), greater<int>());
        int ans = INT_MAX;
        for (auto&& it = mp.begin(); it != mp.end(); it++) {
            int curr = n - it->second;
            curr += countless(it->first, 0, n, mins);
            curr += countmore(it->first, 0, n, maxs);
            ans = min(ans, curr);
        }
        return ans;
    }
    
    int countless(int target, int left, int right, vector<int>& mins) {
        int n = mins.size();
        if (left == right - 1) {
            if (target < mins[left])
                return n - left;
            else 
                return n - left - 1;
        }
        int mid = (left + right) / 2;
        if (target < mins[mid])
            return countless(target, left, mid, mins);
        else
            return countless(target, mid, right, mins);
    }
    
    int countmore(int target, int left, int right, vector<int>& maxs) {
        int n = maxs.size();
        if (left == right - 1) {
            if (target > maxs[left])
                return n - left;
            else 
                return n - left - 1;
        }
        int mid = (left + right) / 2;
        if (target > maxs[mid])
            return countmore(target, left, mid, maxs);
        else
            return countmore(target, mid, right, maxs);
    }
};