class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            int writer = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    ans[j][m-1-i] = '*';
                    writer = j - 1;
                }
                else if (box[i][j] == '#') {
                    ans[writer][m-1-i] = '#';
                    --writer;
                }
            }
        }
        return ans;
    }
};















class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<int>> count(m, vector<int>(n + 1, -1));
        for (int i = 0; i < m; ++i) {
            int curr = 0;
            for (int j = 0; j < n; ++j) {
                if (box[i][j] == '#')
                    ++curr;
                else if (box[i][j] == '*') {
                    count[i][j] = curr;
                    curr = 0;
                }
            }
            count[i][n] = curr;
        }
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (count[i][j] >= 0) {
                    ans[j][m-1-i] = '*';
                    for (int k = 0; k < count[i][j]; ++k) {
                        ans[j-1-k][m-1-i] = '#';
                    }
                }
            }
            for (int k = 0; k < count[i][n]; ++k) {
                ans[n-1-k][m-1-i] = '#';
            }
        }
        return ans;
    }
};