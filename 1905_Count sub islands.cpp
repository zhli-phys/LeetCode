//784 ms 20%; 265.4 MB 20%
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    unordered_set<int> st;
                    dfs(i, j, grid2, st);
                    bool flag = true;
                    for (auto it = st.begin(); it != st.end(); ++it) {
                        int ft = *it / 1000;
                        int sd = *it % 1000;
                        if (grid1[ft][sd] == 0)
                            flag = false;
                        grid2[ft][sd] = 0;
                    }
                    count += flag;
                }
            } 
        }
            
        return count;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid2, unordered_set<int>& st) {
        int m = grid2.size();
        int n = grid2[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0 || st.find(1000 * i + j) != st.end()) 
            return;
        st.insert(1000 * i + j);
        dfs(i - 1, j, grid2, st);
        dfs(i + 1, j, grid2, st);
        dfs(i, j - 1, grid2, st);
        dfs(i, j + 1, grid2, st);
    }
};























//492 ms 60%; 89.2 MB 60%
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    count += dfs(i, j, grid1, grid2, visited);
                    set_zero(i, j, grid2);
                }
            } 
        }
            
        return count;
    }
    
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2,  vector<vector<bool>>& visited) {
        int m = grid2.size();
        int n = grid2[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0 || visited[i][j]) 
            return true;
        visited[i][j] == true;
        if (grid1[i][j] == 0)
            return false;
        return dfs(i - 1, j, grid1, grid2, visited) && dfs(i + 1, j, grid1, grid2, visited)
            && dfs(i, j - 1, grid1, grid2, visited) && dfs(i, j + 1, grid1, grid2, visited);
    }
    
    void set_zero(int i, int j, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) 
            return;
        grid2[i][j] = 0;
        set_zero(i - 1, j, grid2);
        set_zero(i + 1, j, grid2);
        set_zero(i, j - 1, grid2);
        set_zero(i, j + 1, grid2);
    }
