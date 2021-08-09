class Solution {
public:
    string toLowerCase(string s) {
        string lower_s;
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') 
                lower_s.push_back(ch - 'A' + 'a');
            else
                lower_s.push_back(ch);
        }
        return lower_s;
    }
};