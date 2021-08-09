class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(digits);
        bool carry = 0;
        if (ans[n-1] == 9) {
            carry = 1;
            ans[n - 1] = 0;
        } 
        else {
            ans[n - 1]++;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ans[i] + carry > 9) {
                carry = 1;
                ans[i] = 0;
            }
            else {
                ans[i] = ans[i] + carry;
                carry = 0;
                break;
            }
        }
        if (carry)
            ans.insert(ans.begin(), 1);
        return ans;
    }
};