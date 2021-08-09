class Solution {
public:
    bool checkZeroOnes(string s) {
        vector<int> count(2);
        size_t n = s.size();
        int curr_count = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1])
                ++curr_count;
            else {
                count[s[i-1] - '0'] = max(curr_count, count[s[i-1] - '0']);
                curr_count = 1;
            }
        }
        count[s.back() - '0'] = max(curr_count, count[s.back() - '0']);
        return count[0] < count[1];
    }
};