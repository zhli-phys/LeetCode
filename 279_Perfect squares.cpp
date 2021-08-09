class Solution {
public:
    int numSquares(int n) {
        vector<int> least(n + 1, -1);
        least[0] = 0;
        return helper(n, least);
    }
    
    int helper(int n, vector<int>& least) {
        if (least[n] >= 0)
            return least[n];
        int ans = n;
        int start = floor(sqrt((double) n));
        for (int i = start; i > 1; i--) {
            int temp = 1 + helper(n - i*i, least);
            if (temp < ans)
                ans = temp;
        }
        least[n] = ans;
        return ans;
    }
};