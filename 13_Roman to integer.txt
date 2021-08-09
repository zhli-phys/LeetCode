class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'M')
                ans += 1000;
            else if (s[i] == 'D')
                ans += 500;
            else if (s[i] == 'C') {
                if (i < n - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    ans -= 100;
                else 
                    ans += 100;
            }
            else if (s[i] == 'L')
                ans += 50;
            else if (s[i] == 'X') {
                if (i < n - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    ans -= 10;
                else 
                    ans += 10;
            }
            else if (s[i] == 'V')
                ans += 5;
            else if (s[i] == 'I') {
                if (i < n - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    ans -= 1;
                else
                    ans += 1;
            }
        }
        return ans;
    }
};


















class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && mp[s[i]] < mp[s[i+1]])
                num -= mp[s[i]];
            else
                num += mp[s[i]];
        }
        return num;
    }
};