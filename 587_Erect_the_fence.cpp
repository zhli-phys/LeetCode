class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        map<int, int> minY;
        map<int, int, greater<int>> maxY;
        for (auto& tree : trees) {
            if (minY.find(tree[0]) == minY.end()) {
                minY[tree[0]] = tree[1];
                maxY[tree[0]] = tree[1];
            }
            else {
                minY[tree[0]] = min(minY[tree[0]], tree[1]);
                maxY[tree[0]] = max(maxY[tree[0]], tree[1]);
            }
        }
        vector<vector<int>> ans;
        int minX = minY.begin()->first;
        int maxX = (--minY.end())->first;
        if (minX == maxX)
            return trees;
        set<int> maxCol;
        set<int, greater<int>> minCol;
        for (auto& tree : trees) {
            if (tree[0] == minX)
                minCol.insert(tree[1]);
            else if (tree[0] == maxX) 
                maxCol.insert(tree[1]);         
        }
        
        int currX = minX;
        int currY = minY.begin()->second;        
        ans.push_back({currX, currY});
        while (currX < maxX) {
            double minSlope = 1e9;
            int nextX = -1;
            for (auto it = minY.upper_bound(currX); it != minY.end(); ++it) {
                double currSlope = static_cast<double>(it->second - currY) / (it->first - currX);
                if (currSlope < minSlope - 1e-8) {
                    nextX = it->first;
                    minSlope = currSlope;
                }
            }
            currX = nextX;
            currY = minY[nextX];
            if (currY == maxY[nextX])
                maxY.erase(currX);
            ans.push_back({currX, currY});
        }
        for (auto it = (++maxCol.begin()); it != maxCol.end(); ++it) 
            ans.push_back({maxX, *it});         
        currY = ans.back()[1];
        while (currX > minX) {
            double minSlope = 1e9;
            int nextX = -1;
            for (auto it = maxY.upper_bound(currX); it != maxY.end(); ++it) {
                double currSlope = static_cast<double>(it->second - currY) / (it->first - currX);
                if (currSlope < minSlope - 1e-8) {
                    nextX = it->first;
                    minSlope = currSlope;
                }
            }
            currX = nextX;
            currY = maxY[nextX];
            ans.push_back({currX, currY});
        }
        for (auto it = (++minCol.begin()); it != minCol.end(); ++it)
            ans.push_back({minX, *it});
        if (ans.size() > 1 && ans.back() == ans[0])
            ans.pop_back();
        return ans;
    }
};