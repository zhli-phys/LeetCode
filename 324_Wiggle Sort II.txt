class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy(nums);
        sort(copy.begin(), copy.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = copy[(n+i)/2];
            }
            else {
                nums[i] = copy[i/2];
            }
        }
    }
};