//100 ms 63%; 90.3 MB 27%
class Solution {
public:
    Solution(vector<int>& nums) : original(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = original.size();
        vector<int> output(original);
        for (int i = 0; i < n; ++i) 
            swap(output[i], output[rand() % n]);
        return output;
    }
    
private:
    vector<int> original;
};