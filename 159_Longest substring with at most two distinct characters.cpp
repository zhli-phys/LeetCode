//hash map; 20 ms 12%; 7.7 MB 65%
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> count;
        int left = 0;
        int right = 0;
        while (right < n) {
            ++count[s[right]];
            ++right;
            while (count.size() > 2) {
                --count[s[left]];
                if (count[s[left]] == 0)
                    count.erase(s[left]);
                ++left;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};











//4 ms 92%; 6.9 MB 69%
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> count(128);
        int distinct_number = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (count[s[right]] == 0)
                ++distinct_number;
            ++count[s[right]];
            ++right;
            while (distinct_number > 2) {
                --count[s[left]];
                if (count[s[left]] == 0)
                    --distinct_number;
                ++left;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};