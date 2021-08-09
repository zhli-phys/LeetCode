class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return to_int(firstWord) + to_int(secondWord) == to_int(targetWord);
    }
    
    int to_int(const string& s) {
        int n = s.size();
        int exp = 1;
        int output = 0;
        for (int i = n - 1; i >= 0; --i) {
            output += (s[i] - 'a') * exp;
            exp *= 10;
        }
        return output;
    }
};