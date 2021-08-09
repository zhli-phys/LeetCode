class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        queue<int> q;
        int curr = 1;
        int count = 0;
        for (int num : nums) {
            q.push(num);
            curr *= num;
            while(!q.empty() && curr >= k) {
                curr /= q.front();
                q.pop();
            }
            count += q.size();
        }
        return count;
    }
};




//Sliding windows
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int curr = 1;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            curr *= nums[i];
            while (left <= i && curr >= k) {
                curr /= nums[left];
                left++;
            }
            count += (i - left + 1);
        }
        return count;
    }
};