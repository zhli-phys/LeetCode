class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        int n = s.size() - 2;
        for (int i = 1; i < n; ++i) {
            auto first = allChoices(s.substr(1, i));
            auto second = allChoices(s.substr(1 + i, n - i));
            for (auto&& fs : first) 
                for (auto&& sd : second)
                    ans.push_back('(' + fs + ", " + sd+ ')');
        }
        return ans;
    }
    
    vector<string> allChoices(const string& s) {
        vector<string> ans;
        int n = s.size();
        if (n == 1 || s[0] != '0')
            ans.push_back(s);
        if (n == 1 || s.back() == '0')
            return ans;
        else if (s[0] == '0') 
            ans.push_back("0." + s.substr(1));
        else 
            for (int i = 1; i < n; ++i)
                ans.push_back(s.substr(0, i) + '.' + s.substr(i));
        return ans;
    }
};