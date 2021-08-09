class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>();
        }
        vector<string> table(8);
        table[0] = "abc";
        table[1] = "def";
        table[2] = "ghi";
        table[3] = "jkl";
        table[4] = "mno";
        table[5] = "pqrs";
        table[6] = "tuv";
        table[7] = "wxyz";
        queue<string> sol;
        sol.push("");
        for (int i = 0; i < digits.size(); i++) {
            string tablei = table[digits[i] - 50];
            int len = sol.size();
            for (int j = 0; j < len; j++) {
                string temp = sol.front();
                for (int k = 0; k < tablei.size(); k++) {
                    sol.push(temp + tablei[k]);
                }
                sol.pop();
            }
        }
        vector<string> result;
        int len = sol.size();
        for (int i = 0; i < len; i++) {
            result.push_back(sol.front());
            sol.pop();
        }
        return result;
    }
};