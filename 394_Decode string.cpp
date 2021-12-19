class Solution {
public:
    string decodeString(string s) {
        return decode(0, s.size() - 1, s);
    }
    
    string decode(int start, int end, const string& s) {
        string ans;
        if (start >= s.size() || start > end)
            return ans;
        int i = start;
        while (i <= end) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans.push_back(s[i]);
                ++i;
            }
            else {
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    count = count * 10 + s[i] - '0';
                    ++i;
                }
                int bracket = 1;
                int newStart = i + 1;
                int newEnd = newStart;
                while (bracket > 0) {
                    if (s[newEnd] == '[')
                        ++bracket;
                    else if (s[newEnd] == ']')
                        --bracket;
                    ++newEnd;
                }
                for (int j = 0; j < count; ++j)
                    ans += decode(newStart, newEnd - 2, s);
                i = newEnd;
            }
        }
        return ans;
    }
};





















class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<int> nums;
        stack<string> strs;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > 60)
                ans += s[i];
            else {
                int count = 0;
                int num;
                string str;
                while (true) {
                    while (s[i] > 95 || (s[i] > 64 && s[i] < 91)) {
                        strs.top() += s[i];
                        i++;
                    }
                    if (s[i] < 60) {
                        string temp = "";
                        while (s[i] < 60) {
                            temp += s[i];
                            i++;
                        }
                        num = stoi(temp);
                        nums.push(num);
                        count++;
                        i++;
                        str = "";
                        while (s[i] > 95 || (s[i] > 64 && s[i] < 91)) {
                            str += s[i];
                            i++;
                        }
                        strs.push(str);
                    }
                    while (i < s.size() && s[i] == ']') {
                        count--;
                        num = nums.top();
                        nums.pop();
                        str = strs.top();
                        strs.pop();
                        string new_str = "";
                        if(!strs.empty()) 
                            new_str = strs.top();
                        for (int j = 0; j < num; j++)
                            new_str += str;
                        if(!strs.empty()) {
                            strs.pop();
                            strs.push(new_str);
                        }
                        i++;
                    }
                    if (count == 0) {
                        i--;
                        break;
                    }
                }
                for (int j = 0; j < num; j++)
                    ans += str;
            }
        }
        return ans;
    }
};