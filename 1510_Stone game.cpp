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