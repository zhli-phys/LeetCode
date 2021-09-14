class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(26);
        for (char ch : text) 
            ++counts[ch - 'a'];
        int ans = INT_MAX;
        ans = min(ans, counts['b'-'a']);
        ans = min(ans, counts[0]);
        ans = min(ans, counts['l'-'a'] / 2);
        ans = min(ans, counts['o'-'a'] / 2);
        ans = min(ans, counts['n'-'a']);
        return ans;
    }
};