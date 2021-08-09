class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        vector<int> dq;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') 
                dq.push_back(-i-1);
            else if (s[i] == ')') {
                if (!dq.empty() && dq.back() < 0)
                    dq.pop_back();
                else 
                    dq.push_back(i+1);
            }
        }
        int count = 0;
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] > 0)
                count++;
            else 
                break;
        }
        queue<string> ans;
        ans.push(s);
        unordered_set<string> checked;
        for (int i = 0; i < count; i++) {
            int m = ans.size();
            for (int j = 0; j < m; j++) {
                string temp = ans.front();
                ans.pop();
                for (int k = 0; k < dq[i] - i; k++) {
                    if (temp[k] == ')') {
                        string temp1 = temp.substr(0, k) + temp.substr(k + 1);
                        if (checked.find(temp1) == checked.end()) {
                            ans.push(temp1);
                            checked.insert(temp1);
                        }
                    }
                }
            }
        }
        reverse(dq.begin() + count, dq.end());
        for (int i = count; i < dq.size(); i++) {
            int m = ans.size();
            for (int j = 0; j < m; j++) {
                string temp = ans.front();
                ans.pop();
                for (int k = temp.size() - 1; k >= - dq[i] - 1 - count; k--) {
                    if (temp[k] == '(') {
                        string temp1 = temp.substr(0, k) + temp.substr(k + 1);
                        if (checked.find(temp1) == checked.end()) {
                            ans.push(temp1);
                            checked.insert(temp1);
                        }
                    }
                }
            }
        }
        vector<string> sol;
        while (!ans.empty()) {
            sol.push_back(ans.front());
            ans.pop();
        }
        return sol;
    }
};