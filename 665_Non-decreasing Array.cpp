class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        if (n <= 2)
            return true;
        int prev = nums[0];
        if (nums[1] < prev) 
            flag = true;
        prev = nums[1];        
        for (int i = 2; i < n; ++i) {
            if (nums[i] >= prev)
                prev = nums[i];
            else {
                if (flag)
                    return false;
                flag = true;
                if (nums[i] >= nums[i-2])
                    prev = nums[i];
                else
                    prev = nums[i-1];
            }
        }
        return true;
    }
};









//Modifies the original array
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        if (n <= 2)
            return true;
        if (nums[1] < nums[0]) 
            flag = true;
        for (int i = 2; i < n; ++i) {
            if (nums[i] < nums[i-1]) {
                if (flag)
                    return false;
                flag = true;
                if (nums[i] < nums[i-2])
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};