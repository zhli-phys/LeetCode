#define M 1000000007
using ll = long long;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int n1 = horizontalCuts.size();
        int n2 = verticalCuts.size();
        int max_h = horizontalCuts[0];
        for (int i = 1; i < n1; ++i)
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i-1]);
        max_h = max(max_h, h - horizontalCuts.back());
        int max_v = verticalCuts[0];
        for (int i = 1; i < n2; ++i)
            max_v = max(max_v, verticalCuts[i] - verticalCuts[i-1]);
        max_v = max(max_v, w - verticalCuts.back());
        return static_cast<ll>(max_h) * max_v % M;
    }
};