class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(26, 0);
        int n = s.size();
        if (t.size() != n)
            return false;
        for (int i = 0; i < n; i++) {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i] != 0)
                return false;
        }
        return true;
    }
};