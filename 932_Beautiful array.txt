class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> output(n);
        build(0, n, output);
        return output;
    }
    
    void build(int pos, int n, vector<int>& output) {
        if (n == 1) {
            output[pos] = 1;
            return;
        }
        int mid = (n + 1) / 2;
        build(pos, mid, output);
        build(pos + mid, n - mid, output);
        for (int i = 0; i < mid; ++i)
            output[pos+i] = output[pos+i] * 2 - 1;
        for (int i = mid; i < n; ++i)
            output[pos+i] *= 2;
    }
};