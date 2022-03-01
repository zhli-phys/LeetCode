class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i = 1; i <= n; ++i)
            ans[i] = ans[i/2] + i % 2;
        return ans;
    }
};













class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1)
                bits[i] = bits[i - 1] + 1;
            else
                bits[i] = bits[i >> 1];
        }
        return bits;
    }
};





class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) 
                bits[i] = bits[i >> 1] + (i & 1);
        return bits;
    }
};