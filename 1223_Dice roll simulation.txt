class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<unordered_map<int, int>>> con(n+1, vector<unordered_map<int, int>>(6));
        return dieSimulator(n, 0, 0, con, rollMax);
    }
    
    long dieSimulator(int n, int i, int rep, vector<vector<unordered_map<int, int>>>& con, vector<int>& rollMax) {
        if (rep > rollMax[i])
            return 0;
        if (n == 0)
            return 1;
        if (con[n][i].count(rep))
            return con[n][i][rep];
        long ans = 0;
        for (int j = 0; j < 6; j++) {
            if (i == j) {
                ans = (ans + dieSimulator(n-1, i, rep+1, con, rollMax)) % 1000000007;
            }
            else {
                ans = (ans + dieSimulator(n-1, j, 1, con, rollMax)) % 1000000007;
            }
        }
        con[n][i][rep] = ans;
        return ans;
    }
};







class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<int>> con(n, vector<int>(6));
        for (int i = 0; i < 6; i++)
            con[0][i] = 1;
        long ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + helper(n-1, i, con, rollMax)) % 1000000007;
        }
        return ans;
    }
    
    long helper(int n, int i, vector<vector<int>>& con, vector<int>& rollmax) {
        if (con[n][i] > 0)
            return con[n][i];
        int ans = 0;
        for (int j = 1; j <= min(rollmax[i], n); j++) {
            for (int k = 0; k < 6; k++) {
                if (k != i) {
                    ans = (ans + helper(n-j, k, con, rollmax)) % 1000000007;
                }
            }
        }
        if (n < rollmax[i])
            ans++;
        con[n][i] = ans;
        //cout << n << i << '\t' << ans << endl;
        return ans;
    }
};









class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<int>> con(n, vector<int>(6));
        vector<vector<int>> uncon(n, vector<int>(6));
        for (int i = 0; i < 6; i++) {
            con[0][i] = 1;
            uncon[0][i] = 1;
        }
        long ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + helper(n-1, i, con, uncon, rollMax)) % 1000000007;
        }
        return ans;
    }
    
    long helper(int n, int i, vector<vector<int>>& con, vector<vector<int>>& uncon, vector<int>& rollmax) {
        if (con[n][i] > 0)
            return con[n][i];
        int ans = 0;
        for (int j = 0; j < min(rollmax[i], n+1); j++) {
            ans = (ans + unhelper(n-j, i, con, uncon, rollmax)) % 1000000007;
        }
        con[n][i] = ans;
        //cout << "con" << n << i << '\t' << ans << endl;
        return ans;
    }
    
    long unhelper(int n, int i, vector<vector<int>>& con, vector<vector<int>>& uncon, vector<int>& rollmax) {
        if (uncon[n][i] > 0)
            return uncon[n][i];
        int ans = 0;
        for (int j = 0; j < 6; j++) {
            if (i != j)
                ans = (ans + helper(n-1, j, con, uncon, rollmax)) % 1000000007;
        }
        uncon[n][i] = ans;
        //cout << "uncon" << n << i << '\t' << ans << endl;
        return ans;
    }
};














#define M 1000000007;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long>> dp(n+1, vector<long>(7));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    dp[i][j] += (dp[i-k][6] - dp[i-k][j]) % M;
                    if (i-k <= 0) {
                        dp[i][j]++;
                        break;
                    }
                }
                dp[i][6] = (dp[i][6] + dp[i][j]) % M;
            }
        }
        if (dp[n][6] < 0)
            return dp[n][6] + M;
        return dp[n][6];
    }
};