class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int curr = lower;
        for (int num : nums) {
            if (num == curr + 1)
                ans.push_back(to_string(curr));
            else if (num > curr + 1)
                ans.push_back(to_string(curr) + "->" + to_string(num - 1));
            curr = num + 1;
        }
        if (upper == curr)
            ans.push_back(to_string(curr));
        else if (upper > curr)
            ans.push_back(to_string(curr) + "->" + to_string(upper));
        return ans;
    }
};