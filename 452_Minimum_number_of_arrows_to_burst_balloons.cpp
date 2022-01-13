class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), mySmaller);
        int count = 1;
        int currEnd = points[0][1];
        int n = points.size();
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > currEnd) {
                ++count;
                currEnd = points[i][1];
            }
        }
        return count;
    }
    
    static bool mySmaller(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};