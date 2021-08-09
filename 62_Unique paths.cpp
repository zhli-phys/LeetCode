class Solution {
public:   
    int uniquePaths(int m, int n) {
        if (m == 1 or n == 1)
            return 1;
        unordered_map<int, unordered_map<int, int>>::iterator it = NumOfPaths.find(m);
        if (it != NumOfPaths.end()) {
            unordered_map<int, int>::iterator it2 = it->second.find(n);
            if (it2 != it->second.end())
                return it2->second;
        }
        int sol = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        NumOfPaths[m][n] = sol;
        return sol;
    }
    
private: 
    unordered_map<int, unordered_map<int, int>> NumOfPaths;
};