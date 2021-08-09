class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < size; i++) {
            if (pos.find(nums[i]) != pos.end()) {
                if (2*nums[i] == target) {
                    int sol[2] = {pos.find(nums[i])->second, i};
                    return vector<int>(sol, sol+2);
                }
            }
            pos.insert(pair(nums[i], i));
        }
        vector<int> mynums(nums);
        sort(mynums.begin(), mynums.end());
        int i = 0;
        int j = size - 1;
        int temp;
        while (true) {
            temp = mynums[i] + mynums[j];
            if (temp == target) 
                break;
            if (temp > target)
                j--;
            else
                i++;
            if (i >= j)
                return vector<int>();
        }
        int sol[2] = {pos.find(mynums[i])->second, pos.find(mynums[j])->second};
        return vector<int>(sol, sol+2);
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < size; i++) {
            if (pos.find(target-nums[i]) != pos.end()) {
                int sol[2] = {pos.find(target-nums[i])->second, i};
                return vector<int>(sol, sol+2);
            }
            pos.insert(pair(nums[i], i));
        }
        return vector<int>();
    }
};