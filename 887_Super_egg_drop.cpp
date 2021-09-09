class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> maxLevel(k);
        vector<int> prev(maxLevel);
        int moves = 0;
        while (maxLevel.back() < n) {
            ++moves;
            for (int i = 0; i < k; ++i)
                prev[i] = maxLevel[i];
            maxLevel[0] = moves;
            for (int i = 1; i < k; ++i)
                maxLevel[i] += 1 + prev[i-1];
        }
        return moves;
    }
};