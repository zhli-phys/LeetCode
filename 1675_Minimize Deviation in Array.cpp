class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minval = INT_MAX;
        priority_queue<int> pq;
        for (int num : nums) {
            if (num % 2 == 1) {
                minval = min(minval, 2 * num);
                pq.push(2 * num);
            }
            else {
                minval = min(minval, num);
                pq.push(num);
            }
        }
        int ans = INT_MAX;
        while (true) {
            int curr = pq.top();
            ans = min(ans, curr - minval);
            if (curr % 2 == 0) {
                minval = min(minval, curr / 2);
                pq.pop();
                pq.push(curr / 2);
            }
            else 
                return ans;
        }
    }
};