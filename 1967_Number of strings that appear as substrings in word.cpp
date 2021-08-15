class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> substrings;
        int count = 0;
        for (auto& pattern : patterns) 
            count += (word.find(pattern) != string::npos);
        return count;
    }
};







class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> substrings;
        int n = word.size();
        for (int i = 0; i < n; ++i) 
            for (int len = 1; len <= n - i; ++len)
                substrings.insert(word.substr(i, len));
        int count = 0;
        for (auto& pattern : patterns) 
            count += (substrings.find(pattern) != substrings.end());
        return count;
    }
};