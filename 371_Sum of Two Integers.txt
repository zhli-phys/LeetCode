class Solution {
public:
    int getSum(int a, int b) {
        bool neg_a = false;
        bool neg_b = false;
        long x = a;
        long y = b;
        if (x < 0) {
            neg_a = true;
            x = -x;
        }
        if (y < 0) {
            neg_b = true;
            y = -y;
        }
        bool neg = false;
        if (neg_a == neg_b) {
            neg = neg_a;
            while (y != 0) {
                int sum = x ^ y;
                int carry = (x & y) << 1;
                x = sum;
                y = carry;
            }
        }
        else {
            if (x >= y)
                neg = neg_a;
            else {
                int temp = x;
                x = y;
                y = temp;
                neg = neg_b;
            }
            while (y != 0) {
                int ans = x ^ y;
                int borrow = ((~ x) & y) << 1;
                x = ans;
                y = borrow;
            }
        }
        if (neg)
            return -x;
        else
            return x;
    }
};