class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        float prev = x;
        float curr = prev / 2 + x / (2 * prev);
        while (abs(prev - curr) > 1) {
            prev = curr;
            curr = prev / 2 + x / (2 * prev);
        }
        int ans = floor(curr);
        if (ans * ans <= x)
            return ans;
        else 
            return ans - 1;
    }
};