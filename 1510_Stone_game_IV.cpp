class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        for (int i = 0; i <= n; ++i)
            dp[i] = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (!dp[i-j*j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
















class Solution {
public:
    bool winnerSquareGame(int n) {
        if (n == 0) 
            return false;
        unordered_map<int, bool>::iterator it = win.find(n);
        if (it != win.end()) {
            if (it->second)
                return true;
            else
                return false;
        }
        for (int i = floor(sqrt((double)n)); i > 0; i--) {
            int temp = n - i * i;
            if (!winnerSquareGame(temp)) {
                win[n] = true;
                return true;
            }
        }
        win[n] = false;
        return false;
    }
    
private:
    unordered_map<int, bool> win;
};