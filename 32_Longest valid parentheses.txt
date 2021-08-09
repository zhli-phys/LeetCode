class Solution {
public:
    int longestValidParentheses(string s) {
        int sum = 0;
        int current = -1;
        int max_len = 0;
        bool under = true;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                if (sum == 0) {
                    if (under) {
                        current = i;
                        under = false;
                    }
                    else {
                        if (current >= 0)
                        max_len = max(i - current, max_len);
                    }
                }
                sum++;
            }
            else {
                sum--;
                if (sum < 0) {
                    if (current >= 0 && !under)
                        max_len = max(i - current, max_len);
                    sum = 0;
                    under = true;
                }
            }
        }
        if (sum == 0 && !under && current >= 0) {
            max_len = max(len - current, max_len);
        }
        if (sum > 0) {
            sum = 0;
            under = true;
            current = len;
            for (int i = len - 1; i >= 0; i--) {
                if (s[i] == ')') {
                    if (sum == 0) {
                        if (under) {
                            current = i;
                            under = false;
                        }
                        else {
                            if (current < len)
                            max_len = max(current - i, max_len);
                        }
                    }
                    sum++;
                }
                else {
                    sum--;
                    if (sum < 0) {
                        if (current < len && !under)
                            max_len = max(current - i, max_len);
                        sum = 0;
                        under = true;
                    }
                }
            }
            if (sum == 0 && !under && current < len)
                max_len = max(current + 1, max_len);
        }
        return max_len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int max_len = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') 
                stk.push(i);
            else {
                stk.pop();
                if (!stk.empty()) {
                    max_len = max(max_len, i - stk.top());
                }
                else
                    stk.push(i);
            }
        }
        return max_len;
    }
};