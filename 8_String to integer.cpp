class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        long ans = 0;
        int i = 0;
        while (i < n) {
            if (str[i] == ' ')
                i++;
            else 
                break;
        }
        bool neg = false;
        if (i < n && str[i] == '-') {
            neg = true;
            i++;
        }
        else if (i < n && str[i] == '+') {
            i++;
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            ans = 10 * ans + str[i] - '0';
            if (!neg && ans > INT_MAX)
                return INT_MAX;
            if (neg && -ans < INT_MIN)
                return INT_MIN;
            i++;
        }
        if (neg)
            return -ans;
        else
            return ans;
    }
};











class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool negative = false;
        bool met = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                met = true;
                if (!negative) {
                    ans = 10 * ans + (s[i] - '0');
                    if (ans > INT_MAX)
                        return INT_MAX;
                }
                else {
                    ans = 10 * ans - (s[i] - '0');
                    if (ans < INT_MIN)
                        return INT_MIN;
                }
            }
            else if (!met) {
                if (s[i] == ' ')
                    continue;
                else if (s[i] == '-') {
                    negative = true; 
                    met = true;
                }
                else if (s[i] == '+')
                    met = true;
                else
                    return 0;
            }
            else
                break;
        }
        return ans;
    }
};