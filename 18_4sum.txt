//hash table; use set to remove duplications; O(n^2) 92 ms 33%; O(n^2) 33.7 MB 9%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> four_sums;
        unordered_map<int, vector<pair<int, int>>> two_sums;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it = two_sums.find(target - nums[i] - nums[j]);
                if (it != two_sums.end()) {
                    for (auto&& pos : it->second) {
                        if (pos.second < i) {
                            vector<int> curr({nums[pos.first], nums[pos.second], nums[i], nums[j]});
                            four_sums.insert(curr);
                        }
                    }
                }
                two_sums[nums[i] + nums[j]].push_back({i, j});
            }
        }
        vector<vector<int>> ans;
        for (auto it = four_sums.begin(); it != four_sums.end(); ++it)
            ans.push_back(*it);
        return ans;
    }
};