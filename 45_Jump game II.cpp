class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int current = 0;
        int step = 0;
        int next = current + nums[current];
        while (next < nums.size() - 1) {
            step++;
            int max_pos = next;
            for (int i = current + 1; i <= next; i++) 
                max_pos = max(max_pos, i + nums[i]);
            current = next;
            next = max_pos;
        }
        return step + 1;
    }
};









class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int curr = 0;
        int next = nums[0];
        int step = 1;
        while (next < n - 1) {
            int temp = next;
            for (int i = curr + 1; i <= temp; ++i) 
                next = max(next, i + nums[i]);
            curr = temp;
            ++step;
        }
        return step;
    }
};