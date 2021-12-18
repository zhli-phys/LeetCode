class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> digitN;
        while (n > 0) {
            digitN.push_back(n % 10);
            n /= 10;
        }
        int m = digits.size();
        vector<int> digit(m);
        for (int i = 0; i < m; ++i) {
            digit[i] = digits[i][0] - '0';
        }
        reverse(digitN.begin(), digitN.end());
        int ans = 0;
        for (int j = digitN.size() - 1; j >= 1; --j)
            ans += power(m, j);
        explore(0, digitN, digit, ans);
        return ans;
    }
    
    void explore(int i, vector<int>& digitN, vector<int>& digit, int& ans) {
        int mN = digitN.size();
        if (i >= mN) {
            ++ans;
            return;
        }
        int m = digit.size();        
        for (int j = 0; j < m; ++j) {
            if (digit[j] < digitN[i])
                ans += power(m, mN - i - 1);
            else if (digit[j] == digitN[i])
                explore(i + 1, digitN, digit, ans);
            else
                break;
        }
    }
    
    int power(int m, int n) {
        int ans = 1;
        for (int i = 0; i < n; ++i)
            ans *= m;
        return ans;
    }
};