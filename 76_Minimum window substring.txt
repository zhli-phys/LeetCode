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