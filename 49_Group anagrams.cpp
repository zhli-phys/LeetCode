class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<bool> visited(len, false);
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < len; i++) {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(strs[i]);
        }
        vector<vector<string>> sol(0);
        for (unordered_map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); it++)
            sol.push_back(it->second);
        return sol;
    }
};