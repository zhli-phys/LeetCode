class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int currMin = INT_MAX;
        priority_queue<int> pq;
        for (int num : nums) {
            if (num % 2 == 1)
                num *= 2;
            currMin = min(currMin, num);
            pq.push(num);
        }
        int ans = pq.top() - currMin;
        while (pq.top() % 2 == 0) {
            int newNum = pq.top() / 2;
            pq.pop();
            currMin = min(currMin, newNum);
            pq.push(newNum);
            ans = min(ans, pq.top() - currMin);
        }
        return ans;
    }
};