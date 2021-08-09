class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int curr = 0;
        vector<int> ans;
        for (int num : nums) {
            curr += num;
            ans.push_back(curr);
        }
        return ans;
    }
};