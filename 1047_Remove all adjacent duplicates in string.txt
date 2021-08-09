//O(n^2) 12 ms; O(n) 12 MB 18%
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        vector<int> presence(n, true);
        int prev = 0;
        for (int i = 1; i < n; ++i) {
            if (prev >= 0 && s[i] == s[prev]) {
                presence[i] = false;
                presence[prev] = false;
                while (prev >= 0 && !presence[prev])
                    --prev;
            }
            else
                prev = i;
        }
        string ans;
        for (int i = 0; i < n; ++i)
            if (presence[i])
                ans += s[i];
        return ans;
    }
};








//deque; O(n) 24 ms; O(n) 10.7 MB
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        deque<char> dq;
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.back() == s[i])
                dq.pop_back();
            else
                dq.push_back(s[i]);
        }
        string ans;
        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};













//stack; O(n) 12 ms 97%; O(1) 10.1 MB 71%
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; ++i) {
            if (ans.size() > 0 && ans.back() == s[i])
                ans.pop_back();
            else
                ans += s[i];
        }
        return ans;
    }
};