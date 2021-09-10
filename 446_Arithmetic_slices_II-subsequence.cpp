using ll = long long;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        vector<unordered_map<ll, ll>> dp(n);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ll curr = nums[i];
            for (int j = 0; j < i; ++j) {
                if (dp[j].find(curr - nums[j]) != dp[j].end()) {
                    ans += dp[j][curr - nums[j]];
                    dp[i][curr - nums[j]] += dp[j][curr - nums[j]] + 1;
                }
                else
                    ++dp[i][curr - nums[j]];
            }                
        }
        return ans;
    }
};












using ll = long long;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll, unordered_map<ll, ll>> count;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ll curr = nums[i];
            if (count.find(curr) != count.end()) {
                auto it = count.find(nums[i]);
                for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
                    ans += it1->second;
                    count[curr + it1->first][it1->first] += it1->second;
                }
            }
            for (int j = 0; j < i; ++j) {
                ++count[2 * curr - nums[j]][curr - nums[j]];
            }                
        }
        return ans;
    }
};