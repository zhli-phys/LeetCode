class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        string ans;
        int carry = 0;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                int curr = carry + (num1[n1-1-i] - '0') * (num2[n2-1-j] - '0');
                carry = curr / 10;
                curr %= 10;
                insert(curr, i + j, ans);
            }
            if (carry > 0) {
                insert(carry, i + n2, ans);
                carry = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void insert(int curr, int pos, string& ans) {
        if (ans.size() < pos + 1) 
            ans.push_back('0' + curr % 10);
        else {
            curr += (ans[pos] - '0');
            ans[pos] = ('0' + (curr % 10));
        }
        if (curr >= 10)
            insert(curr / 10, pos + 1, ans);
    }
};