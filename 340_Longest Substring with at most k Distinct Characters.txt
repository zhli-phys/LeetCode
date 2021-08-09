class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0)
            return 0;
        int ans = 0;
        queue<char> q;
        vector<int> counts(128);
        int distinct = 0;
        for (char ch : s) {
            if (counts[ch] > 0) {
                q.push(ch);
                counts[ch]++;
            }
            else {
                if (distinct < k) {
                    q.push(ch);
                    counts[ch]++;
                    distinct++;
                }
                else {
                    while (counts[q.front()] > 1) {
                        counts[q.front()]--;
                        q.pop();
                    }
                    counts[q.front()]--;
                    q.pop();
                    q.push(ch);
                    counts[ch]++;
                }
            }
            ans = max(ans, (int) q.size());
        }
        return ans;
    }
};

















class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0)
            return 0;
        int ans = 0;
        queue<char> q;
        unordered_map<char, int> mp;
        for (char ch : s) {
            if (mp.count(ch)) {
                mp[ch]++;
                q.push(ch);
            }
            else {
                if (mp.size() < k) {
                    mp[ch] = 1;
                    q.push(ch);
                }
                else {
                    while (mp[q.front()] > 1) {
                        mp[q.front()]--;
                        q.pop();
                    }
                    mp.erase(q.front());
                    q.pop();
                    q.push(ch);
                    mp[ch] = 1;
                }
            }
            ans = max(ans, (int) q.size());
        }
        return ans;
    }
};












class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0)
            return 0;
        int ans = 0;
        int left = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        for (int right = 0; right < n; right++) {
            if (mp.count(s[right])) 
                mp[s[right]]++;
            else {
                if (mp.size() < k) 
                    mp[s[right]] = 1;
                else {
                    while (mp[s[left]] > 1) {
                        mp[s[left]]--;
                        left++;
                    }
                    mp.erase(s[left]);
                    left++;
                    mp[s[right]] = 1;
                }
            }
            ans = max(ans, (right - left + 1));
        }
        return ans;
    }
};