class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string chars("");
        helper(n, k, visited, chars);
        return chars;
    }
    
    bool helper(int n, int k, unordered_set<string>& visited, string& chars) {
        if (visited.size() == pow(k, n))
            return true;
        if (chars.size() >= n - 1) {
            string prefix(chars.end() - n + 1, chars.end());
            for (int i = 0; i < k; i++) {
                prefix.push_back('0' + i);
                unordered_set<string>::iterator it = visited.find(prefix);
                if (it == visited.end()) {
                    visited.insert(prefix);
                    chars.push_back('0' + i);
                    if (helper(n, k, visited, chars))
                        return true;
                    else {
                        visited.erase(prefix);
                        chars.pop_back();
                    }
                }
                prefix.pop_back();
            }
        }
        else {
            for (int i = 0; i < k; i++) {
                chars.push_back('0' + i);
                if (helper(n, k, visited, chars))
                    return true;
                else
                    chars.pop_back();
            }
        }
        return false;
    }
};