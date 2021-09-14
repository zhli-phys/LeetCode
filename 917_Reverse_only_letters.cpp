class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isLetter(s[i]))
                ++i;
            else if (!isLetter(s[j]))
                --j;
            else {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
    
    inline bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};