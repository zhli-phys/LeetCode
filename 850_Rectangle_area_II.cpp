#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> hor;
        set<int> ver;
        for (auto& rec : rectangles) {
            hor.insert(rec[0]);
            hor.insert(rec[2]);
            ver.insert(rec[1]);
            ver.insert(rec[3]);
        }
        vector<int> ht;
        vector<int> vt;
        for (auto it = hor.begin(); it != hor.end(); ++it)
            ht.push_back(*it);
        for (auto it = ver.begin(); it != ver.end(); ++it)
            vt.push_back(*it);
        int m = ht.size() - 1;
        int n = vt.size() - 1;
        vector<vector<bool>> filled(m, vector<bool>(n));
        for (auto& rec: rectangles) 
            for (int i = 0; i < m; ++i) 
                for (int j = 0; j < n; ++j) 
                    if (rec[0] <= ht[i] && rec[2] >= ht[i+1]
                       && rec[1] <= vt[j] && rec[3] >= vt[j+1]) 
                        filled[i][j] = true;
        ll ans = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (filled[i][j])                    
                    ans = (ans + static_cast<ll>(ht[i+1] - ht[i]) * (vt[j+1] - vt[j])) % M;
        return ans;
    }
};