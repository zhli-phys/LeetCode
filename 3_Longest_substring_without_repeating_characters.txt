class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        vector<int> pos(128, -1);
        int maxlen = 0;
        int letter;
        for (int i = 0; i < s.size(); i++) {
            letter = s[i];
            int temp = pos[letter];
            if (temp >= 0 && s[temp] == letter) {
                for (int j = 0; j < 128; j++) {
                    if (j == letter)
                        continue;
                    if (pos[j] < temp) {
                        if (pos[j] >= 0 && i - pos[j] > maxlen)
                            maxlen = i - 1 - pos[j];
                        pos[j] = temp;
                    }
                }
            }
            else {
                if (i - pos[letter] > maxlen) {
                    maxlen = i - pos[letter];
                }
            }
            pos[letter] = i;
        }
        return maxlen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pos;
        int maxlen = 0;
        char letter;
        int current = -1;
        for (int i = 0; i < s.size(); i++) {
            letter = s[i];
            if (pos.find(letter) == pos.end())
                pos[letter] = current;
            int temp = pos[letter];
            if (temp >= 0 && s[temp] == letter) {
                current = temp;
                for (unordered_map<char, int>::iterator j = pos.begin(); j != pos.end(); j++) {
                    if (j->second < temp) {
                        if (j->second >= 0 && i - 1 - j->second > maxlen)
                            maxlen = i - 1 - j->second;
                        j->second = temp;
                    }
                }
            }
            if (i - temp > maxlen)
                maxlen = i - temp;
            pos[letter] = i;
        }
        return maxlen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int len = 0;
        int maxlen = 0;
        string slice = s.substr(left, len);
        for (int i = 0; i < s.size(); i++) {
            size_t found = slice.find(s[i]);
            if (found == string::npos) {
                len++;
            }
            else {
                len = len - found;
                left += found + 1;
            }
            slice = s.substr(left, len);
            if (len > maxlen)
                maxlen = len;
        }
        return maxlen;
    }
};
