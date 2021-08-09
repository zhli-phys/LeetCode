class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol(1);
        vector<int> init(0);
        sol[0] = init;
        for (int i = 0; i < nums.size(); i++) {
            int len = sol.size();
            for (int j = 0; j < len; j++) {
                vector<int> temp = sol[j];
                temp.push_back(nums[i]);
                sol.push_back(temp);
            }
        }
        return sol;
    }
};