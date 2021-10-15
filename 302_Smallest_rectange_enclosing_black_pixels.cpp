class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        
        int left = 0;
        int right = y;
        while (left < right) {
            int mid = (left + right) / 2;
            if (blackCol(mid, image))
                right = mid;
            else
                left = mid + 1;
        }
        int leftBound = left;
        
        left = y;
        right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (blackCol(mid, image))
                left = mid;
            else
                right = mid - 1;
        }
        int rightBound = left;
        
        left = 0;
        right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (blackRow(mid, image))
                right = mid;
            else
                left = mid + 1;
        }
        int upBound = left;
        
        left = x;
        right = m - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (blackRow(mid, image))
                left = mid;
            else
                right = mid - 1;
        }
        int lowerBound = left;
        
        return (rightBound - leftBound + 1) * (lowerBound - upBound + 1);
    }
    
    bool blackRow(int i, vector<vector<char>>& image) {
        int n = image[0].size();
        for (int j = 0; j < n; ++j)
            if (image[i][j] == '1')
                return true;
        return false;
    }
    
    bool blackCol(int j, vector<vector<char>>& image) {
        int m = image.size();
        for (int i = 0; i < m; ++i)
            if (image[i][j] == '1')
                return true;
        return false;
    }
};