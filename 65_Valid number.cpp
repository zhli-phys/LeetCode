class Solution {
public:
    bool isNumber(string s) {
        size_t e = s.find('e');
        if (e == string::npos)
            e = s.find('E');
        if (e == string::npos)
            return isDecimal(s) || isInteger(s);
        else if (e == s.size())
            return false;
        else 
            return (isDecimal(s.substr(0, e)) || isInteger(s.substr(0, e))) && isInteger(s.substr(e + 1));
    }
    
    inline bool allDigits(string s) {
        for (char ch : s) 
            if (ch < '0' || ch > '9')
                return false;
        return true;
    }
    
    bool isDecimal(string s) {
        if (s.empty())
            return false;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
        if (s.empty() || s == ".")
            return false;
        size_t dot = s.find('.');
        if (dot == string::npos)
            return allDigits(s);
        else if (dot == s.size())
            return allDigits(s.substr(0, s.size() - 1));
        else
            return allDigits(s.substr(0, dot)) && allDigits(s.substr(dot+1));
    }
    
    bool isInteger(string s) {
        if (s.empty())
            return false;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
        return !s.empty() && allDigits(s);
    }
};














class Solution {
public:
    bool isNumber(string s) {
        size_t n = s.size();
        bool sign_met = false;
        bool dot_met = false;
        bool e_met = false;
        for (size_t i = 0; i < n; ++i) {
            if (isDigit(s[i]))
                continue;
            else if (s[i] == '+' || s[i] == '-') {
                if (sign_met || i == n - 1 || (s[i+1] != '.' && !isDigit(s[i+1])) || 
                    (i != 0 && s[i-1] != 'e' && s[i-1] != 'E'))
                    return false;
                sign_met = true;
            }
            else if (s[i] == '.') {
                if (dot_met || ((i == 0 || !isDigit(s[i-1])) && (i == n - 1 || !isDigit(s[i+1]))))
                    return false;
                dot_met = true;
            }
            else if (s[i] == 'E' || s[i] == 'e') {
                if (e_met || i == 0 || i == n - 1 || 
                    (s[i-1] != '.' && !isDigit(s[i-1]) && s[i+1] != '+' && s[i+1] != '-' && !isDigit(s[i+1])))
                    return false;
                e_met = true;
                sign_met = false;
                dot_met = true;
            }
            else
                return false;
        }
        return true;
    }
    
    inline bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
};