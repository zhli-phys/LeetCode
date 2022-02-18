class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        vector<int> use;
        vector<int> removeIdx;
        for (int i = 0; i < n; ++i) {
            while (!use.empty() && removeIdx.size() < k && num[use.back()] > num[i]) {
                removeIdx.push_back(use.back());
                use.pop_back();
            }
            use.push_back(i);
        }
        while (removeIdx.size() < k) {
            removeIdx.push_back(use.back());
            use.pop_back();
        }
        string ans;
        bool metNonzero = false;
        for (int idx : use) {
            if (num[idx] == '0' && !metNonzero)
                continue;
            else {
                metNonzero = true;
                ans.push_back(num[idx]);
            }
        }
        return ans.empty() ? "0" : ans;
    }
};