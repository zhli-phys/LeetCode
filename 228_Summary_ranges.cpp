class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        string curr;
        for (int i = 0; i < n; ++i) {
            if (curr == "") {
                curr += to_string(nums[i]);
            }
            else if (nums[i] > nums[i-1] + 1) {
                if (nums[i-1] > stoi(curr)) {
                    curr += "->";
                    curr += to_string(nums[i-1]);
                }
                ans.push_back(curr);
                curr = to_string(nums[i]);
            }
        }
        if (nums.back() > stoi(curr)) {
            curr += "->";
            curr += to_string(nums.back());
        }
        ans.push_back(curr);
        return ans;
    }
};