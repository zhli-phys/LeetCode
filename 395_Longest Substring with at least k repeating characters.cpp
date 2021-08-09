class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        vector<vector<int>> vec(26, vector<int>(n+1));
        vector<int> counts(26);
        for (int i = 1; i <= n; i++) {
            counts[s[i-1]-'a']++;
            for (int j = 0; j < 26; j++)
                vec[j][i] = counts[j];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                bool good = true;
                for (int l = 0; l < 26; l++) {
                    if (vec[l][j] - vec[l][i] > 0 && vec[l][j] - vec[l][i] < k) {
                        good = false;
                        break;
                    }
                }
                if (good && j - i > ans)
                    ans = j - i;
            }
        }
        return ans;
    }
};















class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return helper(0, n, s, k);
    }
    
    int helper(int left, int right, string& s, int k) {
        if (right - left < k)
            return 0;
        vector<int> counts(26);
        for (int i = left; i < right; i++) 
            counts[s[i]-'a']++;
        bool good = true;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0 && counts[i] < k) {
                good = false;
                break;
            }
        }
        if (good)
            return right - left;
        int ans = 0;
        int i = 0, j = 0;
        while (j < right) {
            if (counts[s[j]-'a'] < k) {
                ans = max(ans, helper(i, j, s, k));
                i = j + 1;
            }
            j++;
        }
        ans = max(ans, helper(i, j, s, k));
        return ans;
    }
};
















class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1)
            return s.size();
        vector<int> vec(26);
        for (char ch: s)
            vec[ch-'a']++;
        int unique = 0;
        for (int i = 0; i < 26; i++) {
            if (vec[i] != 0) {
                unique++;
                vec[i] = 0;
            }                
        }
        
        int ans = 0;
        int n = s.size();
        bool good = false;
        for (int i = 1; i <= unique; i++) {
            int left = 0, right = 0;
            int curr = 0;
            while (right < n) {
                if (vec[s[right]-'a'] == 0) {
                    curr++;
                    good = false;
                }
                vec[s[right]-'a']++;
                if (curr > i) {
                    while (vec[s[left]-'a'] != 1) {
                        vec[s[left]-'a']--;
                        left++;
                    }
                    vec[s[left]-'a']--;
                    curr--;
                    left++;
                }
                if (!good) {
                    bool flag = true;
                    for (int j = 0; j < 26; j++) {
                        if (vec[j] > 0 && vec[j] < k) {
                            flag = false;
                            break;
                        }
                    }
                    good = flag;
                }
                if (good) 
                    ans = max(ans, right - left + 1);
                right++;
            }
            for (int j = 0; j < 26; j++)
                vec[j] = 0;
        }
        return ans;
    }
};