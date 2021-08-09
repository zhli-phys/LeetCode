//Time limit exceeded
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans;
        for (int i = 0; i < n; i++) {
            vector<int> counts(26, 0);
            int odds = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) 
                counts[s[j]-'a']++;
            for (int k = 0; k < 26; k++) {
                if (counts[k] % 2 == 1)
                    odds++;
            }
            if (odds / 2 > queries[i][2])
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};








class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<vector<int>> counts(m+1, vector<int>(26, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 26; j++)
                counts[i][j] = counts[i-1][j];
            counts[i][s[i-1]-'a']++;
        }
        vector<bool> ans;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            int odds = 0;
            for (int k = 0; k < 26; k++) {
                if ((counts[queries[i][1]+1][k] - counts[queries[i][0]][k]) % 2 == 1)
                    odds++;
            }
            if (odds / 2 > queries[i][2])
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};