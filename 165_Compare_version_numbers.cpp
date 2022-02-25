class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1, '.');
        vector<int> v2 = split(version2, '.');
        if (v1.size() < v2.size()) {
            for (int i = v1.size(); i < v2.size(); ++i)
                v1.push_back(0);
        }
        else {
            for (int i = v2.size(); i < v1.size(); ++i)
                v2.push_back(0);
        }
        if (v1 < v2)
            return -1;
        else if (v1 > v2)
            return 1;
        else
            return 0;
    }
    
    static vector<int> split(const string& s, char d) {
        int n = s.size();
        vector<int> ans;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == d) {
                ans.push_back(curr);
                curr = 0;
            }
            else
                curr = 10 * curr + (s[i] - '0');
        }
        ans.push_back(curr);
        return ans;
    }
};