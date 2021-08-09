class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> sk;
        int thrd = INT_MAX;
        for (int num : nums) {
            if (num > thrd)
                return true;
            if (sk.empty() || num > sk.top())
                sk.push(num);
            else if (sk.size() == 1) {
                sk.pop();
                sk.push(num);
            }
            else {
                thrd = min(thrd, sk.top());
                sk.pop();
                if (num <= sk.top()) 
                    sk.pop();
                sk.push(num);
            }
            if (sk.size() == 3)
                return true;
        }
        return false;
    }
};













class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (int num : nums) {
            if (num <= first)
                first = num;
            else if (num <= second)
                second = num;
            else
                return true;
        }
        return false;
    }
};