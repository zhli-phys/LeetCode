class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for (int i = n - 2; i >= 0; --i) {
            shifts[i] += shifts[i + 1];
            shifts[i] %= 26;
        }            
        string ans;
        for (int i = 0; i < n; ++i) 
            ans.push_back((s[i] - 'a' + shifts[i]) % 26 + 'a');
        return ans;
    }
};