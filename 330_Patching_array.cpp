using ll = long long;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ll front = 0;
        int count = 0;
        for (int num : nums) {
            while (front < n && front < num - 1) {
                front = 2 * front + 1;
                ++count;
            }
            front += num;
            if (front >= n)
                return count;
        }
        while (front < n) {
            front = 2 * front + 1;
            ++count;
        }
        return count;
    }
};