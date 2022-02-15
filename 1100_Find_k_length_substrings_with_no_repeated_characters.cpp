class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (n < k || k > 26)
            return 0;
        vector<int> count(26);
        for (int i = 0; i < k; ++i)
            ++count[s[i]-'a'];
        int ans = unique(count);
        for (int i = k; i < n; ++i) {
            ++count[s[i]-'a'];
            --count[s[i-k]-'a'];
            ans += unique(count);
        }
        return ans;
    }
    
    bool unique(vector<int>& count) {
        for (int i = 0; i < 26; ++i)
            if (count[i] > 1)
                return false;
        return true;
    }
};