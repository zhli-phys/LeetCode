//Brute force, O(2^n), 0 ms, extra space
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> xors;
        size_t n = nums.size();
        xors.push_back(0);
        for (size_t i = 0; i < n; ++i) {
            size_t m = xors.size();
            for (size_t j = 0; j < m; ++j)
                xors.push_back(nums[i] ^ xors[j]);
        }
        return accumulate(xors.begin(), xors.end(), 0);
    }
};





//Bit mask, O(2^n), 8 ms, no extra spacce
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> xors;
        size_t n = nums.size();
        int sum = 0;
        int limit = 1 << n;
        for (int i = 0; i < limit; ++i) {
            int curr = 0;
            for (size_t j = 0; j < n; ++j) {
                if (i & 1 << j)
                    curr ^= nums[j];
            }
            sum += curr;
        }
        return sum;
    }
};








//Mathematical solution, O(n), 0 ms, no extra space
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> xors;
        size_t n = nums.size();
        int sum = 0;
        for (size_t i = 0; i < n; ++i) 
            sum |= nums[i];
        sum *= 1 << (n - 1);
        return sum;
    }
};