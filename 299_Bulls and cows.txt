class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int n = secret.size();
        vector<int> sec(10, 0);
        vector<int> gue(10, 0);
        for (int i = 0; i < n; i++) {
            sec[secret[i] - '0']++;
            gue[guess[i] - '0']++;
            if (secret[i] == guess[i])
                bulls++;
        }
        for (int i = 0; i < 10; i++)
            cows += min(sec[i], gue[i]);
        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};