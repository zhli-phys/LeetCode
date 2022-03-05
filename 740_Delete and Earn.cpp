class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums)
            ++mp[num];
        int m = mp.size();
        vector<int> nm;
        for (auto& p : mp)
            nm.push_back(p.first);
        vector<int> dp(m+1);
        dp[1] = mp.begin()->first * mp.begin()->second;
        for (int i = 2; i <= m; ++i) {
            if (nm[i-2] == nm[i-1] - 1) {
                dp[i] = max(nm[i-1] * mp[nm[i-1]] + dp[i-2], dp[i-1]);
            }
            else {
                dp[i] = nm[i-1] * mp[nm[i-1]] + dp[i-1];
            }
        }
        return dp.back();
    }
};














class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> counts;
        for (int num : nums) 
            counts[num]++;
        vector<vector<int>> vec;
        for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); it++) {
            vector<int> bi(2);
            bi[0] = it->first;
            bi[1] = it->second;
            vec.push_back(bi);
        }
        sort(vec.begin(), vec.end());
        int n = vec.size();
        vector<int> dp(n+1);
        dp[n-1] = vec[n-1][0] * vec[n-1][1];
        for (int i = n-2; i >= 0; i--) {
            if (vec[i+1][0] - vec[i][0] > 1)
                dp[i] = vec[i][0] * vec[i][1] + dp[i+1];
            else 
                dp[i] = max(vec[i][0] * vec[i][1] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};