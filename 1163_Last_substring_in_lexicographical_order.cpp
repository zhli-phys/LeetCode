class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        char maxChar = 'a';
        for (char ch : s) 
            maxChar = max(ch, maxChar);
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (s[i] == maxChar)
                pos.push_back(i);
        int len = 1;
        int m = pos.size();
        while (m > 1) {
            char nextChar = 'a';
            for (int i = 0; i < m; ++i) {
                if (pos[i] + len > n)
                    pos[i] = -1;
                else
                    nextChar = max(nextChar, s[pos[i] + len]);
            }
            for (int i = 0; i < m; ++i) {
                if ((i >= 1 && pos[i] - pos[i-1] == len) || (pos[i] >= 0 && s[pos[i] + len] != nextChar))
                    pos[i] = -1;
            }
            int index = 0;
            for (int i = 0; i < m; ++i) {
                if (pos[i] >= 0) {
                    pos[index] = pos[i];
                    ++index;
                }
            }
            m = index;
            ++len;
        }
        return s.substr(pos[0]);
    }
};







// The following solution runs very fast and works for all the test case in LeetCode, but it is wrong! 
// For example, it does not work for "zbzazbzz"
class Solution {
public:   
    string lastSubstring(string s) {
        int n = s.size();
        char maxChar = 'a';
        for (char ch : s) 
            maxChar = max(ch, maxChar);
        int pos = s.find(maxChar);
        for (int i = pos + 1; i < n; ++i) {
            if (s[i] == maxChar) {
                int j = 1;
                while (i + j < n) {
                    if (s[pos + j] < s[i + j]) {
                        pos = i;
                        i = i + j - 1; // should not have this!
                        break;
                    }
                    else if (s[pos + j] > s[i + j]) {
                        i = i + j - 1;
                        break;
                    }
                    ++j;
                }
            }
        }
        return s.substr(pos);
    }
};