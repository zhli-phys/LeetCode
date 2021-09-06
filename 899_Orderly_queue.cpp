class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        else {
            int n = s.size();
            string minstr = s;
            for (int i = 1; i < n; ++i) {
                string curr = s.substr(i) + s.substr(0, i);
                minstr = min(minstr, curr);
            }
            return minstr;
        }
    }
};