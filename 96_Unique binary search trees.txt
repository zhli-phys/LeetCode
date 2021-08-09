class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        unordered_map<int, int>::iterator it = nums.find(n);
        if (it != nums.end())
            return it->second;
        int sol = 0;
        for (int i = 0; i < n; i++) 
            sol = sol + numTrees(i) * numTrees(n - i- 1);
        nums[n] = sol;
        return sol;
    }
    
private:
    unordered_map<int, int> nums;
};




class Solution {
public:
    int numTrees(int n) {
        vector<int> nums;
        nums.push_back(1);
        for(int i = 1; i <= n; i++) {
            int temp = 0;
            for (int j = 0; j < i; j++)
                temp = temp + nums[j] * nums[i - j - 1];
            nums.push_back(temp);
        }
        return nums[n];
    }
};