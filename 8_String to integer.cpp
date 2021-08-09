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