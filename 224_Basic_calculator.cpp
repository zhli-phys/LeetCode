class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<string> postOrder;
        stack<string> ops;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+') {
                while (!ops.empty() && ops.top() != "(") {
                    postOrder.push_back(ops.top());
                    ops.pop();
                }
                ops.push("+");
            }
            else if (s[i] == '-') {
                int j = i - 1;
                while (j >= 0 && s[j] == ' ') 
                    --j;
                if (j < 0 || s[j] == '(')
                    postOrder.push_back("0");
                while (!ops.empty() && ops.top() != "(") {
                    postOrder.push_back(ops.top());
                    ops.pop();
                }
                ops.push("-");
            }
            else if (s[i] == '(') {
                ops.push("(");
            }
            else if (s[i] == ')') {
                while (ops.top() != "(") {
                    postOrder.push_back(ops.top());
                    ops.pop();
                }
                ops.pop();
            }
            else {
                string num = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    ++i;
                }
                --i;
                postOrder.push_back(num);
            }
        }
        while (!ops.empty()) {
            postOrder.push_back(ops.top());
            ops.pop();
        }
        stack<int> nums;
        for (auto& s : postOrder) {
            if (s == "+") {
                int curr = nums.top();
                nums.pop();
                int prev = nums.top();
                nums.pop();
                nums.push(prev + curr);
            }
            else if (s == "-") {
                int curr = nums.top();
                nums.pop();
                int prev = nums.top();
                nums.pop();
                nums.push(prev - curr);
            }
            else
                nums.push(stoi(s));
        }
        return nums.top();
    }
};