class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        return helper(0, points);
    }
    
    int helper(int i, vector<vector<int>>& points) {
        int n = points.size();
        if (i >= n-1)
            return 1;
        int ans = helper(i+1, points);
        unordered_map<int, unordered_map<int, int>> mp;
        int copy = 1;
        for (int j = i+1; j < n; j++) {
            if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
                copy++;
        }
        ans = max(ans, copy);
        for (int j = i+1; j < n; j++) {
            int x = points[j][0] - points[i][0];
            int y = points[j][1] - points[i][1];
            if (x != 0 || y != 0) {
                reduction(x, y); 
                mp[x][y]++;
                ans = max(ans, mp[x][y] + copy);
            }
        }
        return ans;
    }
    
    void reduction(int& x, int& y) {
        if (x == 0 & y == 0)
            return;
        else if (x == 0) {
            y = 1;
            return;
        }
        else if (y == 0) {
            x = 1;
            return;
        }
        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = !neg;
        }
        if (y < 0) {
            y = -y; 
            neg = !neg;
        }
        int temp_x = x;
        int temp_y = y;
        while (temp_x != 0 && temp_y != 0) {
            if (temp_x >= temp_y)
                temp_x %= temp_y;
            else 
                temp_y %= temp_x;
        }
        int gcf = max(temp_x, temp_y);
        x /= gcf;
        y /= gcf;
        if (neg)
            y = -y;
    }
};