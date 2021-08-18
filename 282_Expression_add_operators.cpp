using ll = long long;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        int n = num.size();
        for (int j = 1; j <= n; ++j) {
            auto currStr = num.substr(0, j);
            if (j > 1 && currStr[0] == '0')
                break;
            ll currNum = stoll(currStr);
            dfs(j, num, currStr, currNum, currNum, target, ans);
        }
        return ans;
    }
    
    void dfs(int i, const string& num, string curr, ll last, ll value, ll target, vector<string>& ans) {
        int n = num.size();
        if (i == n) {
            if (value == target)
                ans.push_back(curr);
        }
        for (int j = 1; j <= n - i; ++j) {
            auto currStr = num.substr(i, j);
            if (j > 1 && currStr[0] == '0')
                break;
            ll currNum = stoll(currStr);
            dfs(i + j, num, curr + '+' + currStr, currNum, value + currNum, target, ans);
            dfs(i + j, num, curr + '-' + currStr, -currNum, value - currNum, target, ans);
            dfs(i + j, num, curr + '*' + currStr, last * currNum, value - last + last * currNum, target, ans);
        }
    }
};











//Time limit exceeded
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        string ops;
        vector<string> ans;
        dfs(num, ops, target, ans);
        return ans;
    }
    
    void dfs(const string& num, string& ops, int target, vector<string>& ans) {
        int n = num.size();
        if (ops.size() == n - 1) {
            vector<string> curr;
            string currNum;
            for (int i = 0; i < n - 1; ++i) {
                currNum.push_back(num[i]);
                if (ops[i] != ' ') {
                    curr.push_back(currNum);
                    currNum = "";
                    curr.push_back(string(1, ops[i]));
                }
            }
            currNum.push_back(num.back());
            curr.push_back(currNum);
            if (eval(curr) == target) {
                string currString;
                for (auto& s : curr)
                    currString += s;
                ans.push_back(currString);
            }                
        }
        else {
            for (char ch : string("+-* ")) {
                ops.push_back(ch);
                dfs(num, ops, target, ans);
                ops.pop_back();
            }
        }
    }
    
    int eval(vector<string>& equation) {
        vector<string> postfix;
        stack<string> opts;
        for (auto& eq : equation) {
            if (eq == "*") {
                opts.push(eq);
            }                
            else if (eq == "+" || eq == "-") {
                while (!opts.empty()) {
                    postfix.push_back(opts.top());
                    opts.pop();
                }
                opts.push(eq);
            }
            else
                postfix.push_back(eq);
        }
        while (!opts.empty()) {
            postfix.push_back(opts.top());
            opts.pop();
        }
        int output = 0;
        stack<int> nums;
        for (auto& pst : postfix) {
            if (pst[0] >= '0' && pst[0] <= '9')
                nums.push(stoi(pst));
            else {
                int curr = nums.top();
                nums.pop();
                int prev = nums.top();
                nums.pop();
                output = calc(prev, curr, pst[0]);
                nums.push(output);
            }
        }
        return output;
    }
    
    inline int calc(int prev, int curr, char ch) {
        if (ch == '+')
            return prev + curr;
        else if (ch == '-')
            return prev - curr;
        else
            return prev * curr;
    }
};