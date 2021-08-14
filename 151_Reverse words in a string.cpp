class Solution {
public:
    string reverseWords(string s) {
        string clean_s;
        for (char ch : s) {
            if (ch == ' ') {
                if (!clean_s.empty() && clean_s.back() != ' ')
                    clean_s.push_back(' ');
            }
            else 
                clean_s.push_back(ch);
        }
        if (clean_s.back() == ' ')
            clean_s.pop_back();
        reverse(clean_s.begin(), clean_s.end());
        int prev_pos = 0;
        int n = clean_s.size();
        for (int i = 1; i < n; ++i) {
            if (clean_s[i] == ' ') {
                reverse(clean_s.begin() + prev_pos, clean_s.begin() + i);
                prev_pos = i + 1;
            }
        }
        reverse(clean_s.begin() + prev_pos, clean_s.end());
        return clean_s;
    }
};