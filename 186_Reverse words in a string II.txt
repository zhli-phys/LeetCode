//not in-place; O(n) 36 ms 8%; O(n) 16.8 MB 6%
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        vector<string> vec;
        string curr;
        for (char ch : s) {
            if (ch != ' ')
                curr += ch;
            else {
                vec.push_back(curr);
                curr = "";
            }
        }
        vec.push_back(curr);
        reverse(vec.begin(), vec.end());
        int i = 0;
        for (auto& ss : vec) {
            for (char ch : ss) {
                s[i] = ch;
                ++i;
            }
            if (i < n)
                s[i] = ' ';
            ++i;
        }
    }
};









//reverse the whole string and then reverse each word; O(n) 20 ms 69%; O(1) 16.2 MB 79%
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while (right < n) {
            while (right < n && s[right] != ' ')
                ++right;
            reverse(s.begin() + left, s.begin() + right);
            ++right;
            left = right;
        }
    }
};