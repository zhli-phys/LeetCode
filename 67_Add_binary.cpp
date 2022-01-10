class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int curr = carry;
            if (i >= 0)
                curr += a[i] - '0';
            if (j >= 0)
                curr += b[j] - '0';
            carry = curr / 2;
            curr %= 2;
            ans.push_back('0' + curr);
            --i;
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};