class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> sk;
        for (char ch : s) {
            if (ch == '(') {
                sk.push(-1);
            }                
            else {
                int curr = 0;
                while (sk.top() != -1) {
                    curr += sk.top();
                    sk.pop();
                }
                if (curr == 0)
                    sk.top() = 1;
                else 
                    sk.top() = 2 * curr;
            }
        }
        int ans = 0;
        while (!sk.empty()) {
            ans += sk.top();
            sk.pop();
        }
        return ans;
    }
};