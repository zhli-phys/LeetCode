class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                sk.push(ch);
            else if (ch == ')') {
                if (sk.empty() || sk.top() != '(')
                    return false;
                else
                    sk.pop();
            }
            else if (ch == ']') {
                if (sk.empty() || sk.top() != '[')
                    return false;
                else
                    sk.pop();
            }
            else if (ch == '}') {
                if (sk.empty() || sk.top() != '{')
                    return false;
                else
                    sk.pop();
            }
        }
        return sk.empty();
    }
};













class Solution {
public:
    bool isValid(string s) {
        stack<char> current;
        unordered_map<char, char> par_map;
        par_map.insert(pair<char, char>(')', '('));
        par_map.insert(pair<char, char>('}', '{'));
        par_map.insert(pair<char, char>(']', '['));
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, char>::iterator it = par_map.find(s[i]);
            if (it != par_map.end()) {
                if (current.empty() || current.top() != it->second)
                    return false;
                else
                    current.pop();
            }
            else {
                current.push(s[i]);
            }
        }
        if (current.empty())
            return true;
        else
            return false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<int> current;
        char pars[6] = { '(', ')', '{', '}', '[', ']' };
        int inds[6] = { -1, 1, -2, 2, -3, 3 };
        unordered_map<char, int> par_map;
        for (int i = 0; i < 6; i++) 
            par_map.insert(pair<char, int>(pars[i], inds[i]));
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int>::iterator it = par_map.find(s[i]);
            if (it != par_map.end()) {
                if (it->second > 0) {
                    if (current.empty() || current.top() != -(it->second))
                        return false;
                    else
                        current.pop();
                }
                else {
                    current.push(it->second);
                }
            }
        }
        if (current.empty())
            return true;
        else
            return false;
    }
};