class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int carry = 0;
        int n1 = num1.size();
        int n2 = num2.size();
        int n = max(n1, n2);
        for (int i = 0; i < n; i++) {
            int curr = carry;
            if (i < n1)
                curr += (num1[i] - '0');
            if (i < n2)
                curr += (num2[i] - '0');
            ans.push_back('0' + curr % 10);
            carry = curr / 10;
        }
        if (carry != 0)
            ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};










class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int n = min(n1, n2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        string ans;
        for (int i = 0; i < n; ++i) {
            int curr = carry + (num1[i] - '0') + (num2[i] - '0');
            carry = curr / 10;
            curr %= 10;
            ans += ('0' + curr);
        }
        if (n1 > n) {
            for (int i = n; i < n1; ++i) {
                int curr = carry + (num1[i] - '0');
                carry = curr / 10;
                curr %= 10;
                ans += ('0' + curr);
            }
        }
        else if (n2 > 0) {
            for (int i = n; i < n2; ++i) {
                int curr = carry + (num2[i] - '0');
                carry = curr / 10;
                curr %= 10;
                ans += ('0' + curr);
            }
        }
        if (carry > 0)
            ans += ('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};












