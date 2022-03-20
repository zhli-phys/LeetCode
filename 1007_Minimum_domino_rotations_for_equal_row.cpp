class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> count(7);
        int n = tops.size();
        for (int top : tops)
            ++count[top];
        for (int bottom : bottoms)
            ++count[bottom];
        int target = -1;
        for (int i = 1; i <= 6; ++i) 
            if (count[i] >= n)
                target = i;
        if (target < 0)
            return -1;
        int flipTop = 0;
        int flipBottom = 0;
        for (int i = 0; i< n; ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return -1;
            else if (tops[i] != target)
                ++flipTop;
            else if (bottoms[i] != target)
                ++flipBottom;
        }
        return min(flipTop, flipBottom);
    }
};