class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> dp(8);
        int n = moves.size();
        for (int i = 0; i < n; ++i) {
            int score = 1 - 2 * (i % 2);
            dp[moves[i][0]] += score;
            dp[moves[i][1]+3] += score;
            if (moves[i][0] == moves[i][1])
                dp[6] += score;
            if (moves[i][0] + moves[i][1] == 2)
                dp[7] += score;
        }
        for (int num : dp) {
            if (num == 3)
                return "A";
            else if (num == -3)
                return "B";
        }
        return n == 9 ? "Draw" : "Pending";
    }
};