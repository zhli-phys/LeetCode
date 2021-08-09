class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            vector<vector<int>> sol(1);
            sol[0] = nums;
            return sol;
        }
        vector<vector<int>> sol;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp(nums);
            temp.erase(temp.begin() + i);
            vector<vector<int>> temp_sol = permute(temp);
            for (int j = 0; j < temp_sol.size(); j++) {
                temp_sol[j].push_back(nums[i]);
                sol.push_back(temp_sol[j]);
            }
        }
        return sol;
    }
};