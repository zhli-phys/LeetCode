class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60);
        int ans = 0;
        for (int t : time) {
            t %= 60;
            ans += t == 0 ? count[0] : count[60-t];
            ++count[t];
        }
        return ans;
    }
};