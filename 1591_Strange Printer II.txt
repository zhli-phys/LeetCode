class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        unordered_map<int, vector<int>> colors;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_map<int, vector<int>>::iterator it = colors.find(targetGrid[i][j]);
                if (it == colors.end()) {
                    vector<int> quar(4);
                    quar[0] = i;
                    quar[1] = i;
                    quar[2] = j;
                    quar[3] = j;
                    colors[targetGrid[i][j]] = quar;
                }
                else {
                    if (i < it->second[0])
                        it->second[0] = i;
                    if (i > it->second[1])
                        it->second[1] = i;
                    if (j < it->second[2])
                        it->second[2] = j;
                    if (j > it->second[3])
                        it->second[3] = j;
                }
            }
        }
        int l = colors.size();
        vector<int> five(5);
        vector<vector<int>> colors_vec(l, five);
        unordered_map<int, int> index;
        int count = 0;
        for (unordered_map<int, vector<int>>::iterator it = colors.begin(); it != colors.end(); it++) {
            colors_vec[count][0] = it->first;
            //cout << it->first;
            for (int i = 0; i < 4; i++) {
                colors_vec[count][i+1] = it->second[i];
                //cout << it->second[i];
            }
            //cout << endl;
            index[it->first] = count;
            count++;
        }
        vector<int> row(l, 0);
        vector<vector<int>> before(l, row);
        //cout << l << endl;
        for (int i = 0; i < l; i++) {
            //cout << i << colors_vec[i][0] << colors_vec[i][1] << colors_vec[i][2] << colors_vec[i][3] << colors_vec[i][4] << endl;
            for (int j = colors_vec[i][1]; j <= colors_vec[i][2]; j++) {
                for (int k = colors_vec[i][3]; k <= colors_vec[i][4]; k++) {
                    //cout << j << k << endl;
                    //cout << targetGrid[j][k] << colors_vec[i][0] << endl;
                    if (targetGrid[j][k] != colors_vec[i][0]) {
                        int col = index[targetGrid[j][k]];
                        if (before[i][col] == 0) {
                            before[i][col] = 1;
                            before[col][i] = -1;
                            //cout << i << '\t' << col << endl;
                        }
                        else if (before[i][col] == -1)
                            return false;
                    }
                }
            }
        }
        vector<bool> visited(l, false);
        while (true) {
            int removed = 0;
            for(int i = 0; i < l; i++) {
                if (visited[i])
                    continue;
                bool head = true;
                for(int j = 0; j < l; j++) {
                    if (!visited[j] && before[i][j] == -1) {
                        head = false;
                        break;
                    }                   
                }
                if (head) {
                    removed++;
                    visited[i] = true;
                }
            }
            if (removed == 0)
                break;
        }
        for (int i = 0; i < l; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};