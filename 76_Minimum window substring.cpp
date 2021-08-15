//12 ms 76%; 7.8 Mb 66%
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> target(52);
        for (char ch : t) 
            ++target[pos(ch)];
        vector<int> curr(52);
        int minLen = INT_MAX;
        int minLeft = 0;
        int left = 0;
        int m = s.size();
        for (int right = 0; right < m; ++right) {
            ++curr[pos(s[right])];
            int included = true;
            for (int i = 0; i < 52; ++i) {
                if (curr[i] < target[i]) {
                    included = false;
                    break;
                }
            }
            if (included) {
                while (left <= right) {
                    int leftPos = pos(s[left]);
                    --curr[leftPos];
                    if (curr[leftPos] < target[leftPos]) {
                        if (right - left + 1 < minLen) {
                            minLen = right - left + 1;
                            minLeft = left;
                        }
                        ++left;
                        break;
                    }
                    ++left;
                }
            }
        }
        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(minLeft, minLen);
    }
    
    inline int pos(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return ch - 'A' + 26;
        else
            return ch - 'a';
    }
};









//144 ms 10%; 9.2 MB 24%
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, queue<int>> pos;
        for (int i = 0; i < t.size(); i++) {
            pos[t[i]].push(-1);
        }
        int len = s.size();
        int min_len = len + 1;
        int left;
        for (int i = 0; i < len; i++) {
            unordered_map<char, queue<int>>::iterator it = pos.find(s[i]);
            if (it != pos.end()) {
                it->second.pop();
                it->second.push(i);
                int current_min = 0;
                bool contain = true;
                for (unordered_map<char, queue<int>>::iterator it2 = pos.begin(); it2 != pos.end(); it2++) {
                    int temp = it2->second.front();
                    if (temp < 0) {
                        contain = false;
                        break;
                    }
                    current_min = max(current_min, i - temp + 1);
                }
                if (contain && current_min < min_len) {
                    min_len = current_min;
                    left = i - min_len + 1;
                }
            }
        }
        if (min_len <= len)
            return s.substr(left, min_len);
        else 
            return "";
    }
};