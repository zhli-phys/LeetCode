class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> first(n + 1);
        vector<vector<int>> second(n + 1);
        build(0, n, 0, 0, nums, first);
        build(n, 2*n, 0, 0, nums, second);
        for (int i = 1; i < n; ++i)
            sort(second[i].begin(), second[i].end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        int half = total / 2;
        int ans = *(first[n].begin());
        for (int i = 0; i < n; ++i) {
            for (auto firstNum : first[i]) {
                auto it = lower_bound(second[n-i].begin(), second[n-i].end(), half - firstNum);
                if (it != second[n-i].end() && abs((*it) + firstNum - half) < abs(ans - half))
                    ans = (*it) + firstNum;
                if (it != second[n-i].begin() && abs(*(--it) + firstNum - half) < abs(ans - half))
                    ans = (*it) + firstNum;
            }
        }
        return abs(2 * ans - total);
    }
    
    void build(int i, int j, int count, int curr, vector<int>& nums, vector<vector<int>>& target) {
        int n = nums.size() / 2;
        if (count > n || i > j) 
            return;
        if (i == j || count == n) {
            target[count].push_back(curr);
            return;
        }
        else {
            build(i + 1, j, count, curr, nums, target);
            build(i + 1, j, count + 1, curr + nums[i], nums, target);
        }        
    }
};