class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++) {
            unordered_map<int, int>::iterator it = counts.find(nums[i]);
            if (it == counts.end()) {
                counts.insert(pair<int, int>(nums[i], 1));
            }
            else {
                it->second++;
                if (it->second > n / 2)
                    return nums[i];
            }
        }
        return -1;
    }
};






class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int current = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == current)
                count++;
            else {
                count--;
                if (count < 0) {
                    current = nums[i];
                    count = 1;
                }
            }
        }
        return current;
    }
};














class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for (int num : nums) {
            if (count == 0)
                candidate = num;
            count += (candidate == num ? 1 : -1);
        }
        return candidate;
    }
};