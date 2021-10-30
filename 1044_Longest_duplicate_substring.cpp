#define M 1000000007ll

using ll = long long;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 1;
        int right = n;
        int head = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (validLen(mid, s, head))
                left = mid + 1;
            else
                right = mid;
        }
        return s.substr(head, left - 1);
    }
    
    bool validLen(int len, string& s, int& head) {
        ll pow = mypow(26, len - 1);
        unordered_map<int, vector<int>> mp;
        ll curr = 0;
        int n = s.size();
        int i = 0;
        while (i < len) {
            curr = (curr * 26 + s[i] - 'a') % M;
            ++i;
        }
        mp[curr].push_back(i - len);
        while (i < n) {
            curr = ((curr - (s[i - len] - 'a') * pow) * 26 + s[i] - 'a') % M;
            if (curr < 0)
                curr += M;
            if (mp.find(curr) != mp.end()) {
                for (int start : mp[curr]) {
                    if (equal(start, i + 1 - len, len, s)) {
                        head = start;
                        return true;
                    }                        
                }
            }
            mp[curr].push_back(i + 1 - len);
            ++i;
        }
        return false;
    }
    
    inline int mypow(int a, int n) {
        if (n == 0)
            return 1;
        ll half = mypow(a, n / 2);
        ll ans = (half * half) % M;
        if (n % 2 == 1)
            ans = (ans * a) % M;
        return ans;
    }
    
    inline bool equal(int i1, int i2, int len, string& s) {
        for (int i = 0; i < len; ++i) {
            if (s[i1 + i] != s[i2 + i])
                return false;
        }
        return true;
    }
};