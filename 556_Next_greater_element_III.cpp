using ll = long long;

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10)
            return -1;
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int m = digits.size();
        int firstDrop = 1;
        while (firstDrop < m && digits[firstDrop] >= digits[firstDrop - 1])
            ++firstDrop;
        if (firstDrop == m)
            return -1;
        int firstLarger = 0;
        while (digits[firstLarger] <= digits[firstDrop])
            ++firstLarger;
        swap(digits[firstDrop], digits[firstLarger]);
        sort(digits.begin(), digits.begin() + firstDrop, greater<int>());
        ll ans = 0;
        for (int i = m - 1; i >= 0; --i) 
            ans = 10 * ans + digits[i];
        if (ans > INT_MAX)
            return -1;
        else
            return ans;
    }
};