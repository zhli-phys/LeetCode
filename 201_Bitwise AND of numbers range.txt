//20 ms 17%; 9.1 MB 5%
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int> left_bits;
        while (left > 0) {
            left_bits.push_back(left % 2);
            left /= 2;
        }
        vector<int> right_bits;
        while (right > 0) {
            right_bits.push_back(right % 2);
            right /= 2;
        }
        if (left_bits.size() != right_bits.size())
            return 0;
        int n = left_bits.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (left_bits[i] == right_bits[i])
                ans = 2 * ans + left_bits[i];
            else {
                ans *= (1 << (i + 1));
                break;
            }
        }
        return ans;
    }
};












//20 ms 18%; 5.8 MB 72%
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left /= 2;
            right /= 2;
            ++shift;
        }
        return left << shift;
    }
};












//16 ms 25%; 5.9 MB 25%
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) 
            right &= right - 1;
        return left & right;
    }
};