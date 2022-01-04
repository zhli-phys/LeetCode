class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> digits;
        do {
            digits.push_back(n % 2);
            n /= 2;
        } while (n > 0);
        int ans = 0;
        for (int i = digits.size() - 1; i >= 0; --i)
            ans = 2 * ans + 1 - digits[i];
        return ans;
    }
};