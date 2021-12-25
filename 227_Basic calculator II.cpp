class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        long long ans = 0;
        long long curr = 0;
        char op = 0;
        while (i < n) {
            if (s[i] == ' ')
                ++i;
            else if (s[i] >= '0' && s[i] <= '9') {
                long long num = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    num = 10 * num + s[i] - '0';
                    ++i;
                }
                if (op == 0) {
                    ans = num;
                    curr = num;
                }
                else if (op == '+') {
                    ans += num;
                    curr = num;
                }
                else if (op == '-') {
                    ans -= num;
                    curr = -num;
                }
                else if (op == '*') {
                    ans = (ans - curr) + curr * num;
                    curr *= num;
                }
                else if (op == '/') {
                    ans = (ans - curr) + curr / num;
                    curr /= num;
                }
            }
            else {
                op = s[i];
                ++i;
            }                
        }
        return ans;
    }
};


















class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                string num = "";
                while (s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                nums.push(stoi(num));
            }
            else if (s[i] == '*' || s[i] == '/') {
                if (ops.size() > 0 && (ops.top() == '*' || ops.top() == '/')) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    if (ops.top() == '*')
                        nums.push(a * b);
                    else
                        nums.push(a / b);
                    ops.pop();
                }
                ops.push(s[i]);
                i++;
            }
            else {
                while (ops.size() > 0) {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    if (ops.top() == '*')
                        nums.push(a * b);
                    else if (ops.top() == '/')
                        nums.push(a / b);
                    else if (ops.top() == '+')
                        nums.push(a + b);
                    else
                        nums.push(a - b);
                    ops.pop();
                }
                ops.push(s[i]);
                i++;
            }
        }
        
        while (ops.size() > 0) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            cout << ops.top() << endl;
            if (ops.top() == '*')
                nums.push(a * b);
            else if (ops.top() == '/')
                nums.push(a / b);
            else if (ops.top() == '+')
                nums.push(a + b);
            else
                nums.push(a - b);
            ops.pop();
        }
        return nums.top();
    }
};