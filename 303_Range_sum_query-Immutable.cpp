class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        sums.push_back(sum);
        for (int num : nums) {
            sum += num;
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }
    
private:
    vector<int> sums;
};