class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                sk.push(a + b);
            }
            else if (tokens[i] == "-") {
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                sk.push(a - b);
            }
            else if (tokens[i] == "*") {
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                sk.push(a * b);
            }
            else if (tokens[i] == "/") {
                int b = sk.top();
                sk.pop();
                int a = sk.top();
                sk.pop();
                sk.push(a / b);
            }
            else {
                sk.push(stoi(tokens[i]));
            }
        }
        return sk.top();
    }
};








class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        for (auto&& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") 
                operate(sk, token);
            else 
                sk.push(stoi(token));
        }
        return sk.top();
    }
    
    void operate(stack<int>& sk, const string& token) {
        int second = sk.top();
        sk.pop();
        int first = sk.top();
        sk.pop();
        if (token == "+")
            sk.push(first + second);
        else if (token == "-")
            sk.push(first - second);
        else if (token == "*")
            sk.push(first * second);
        else
            sk.push(first / second);
    }
};