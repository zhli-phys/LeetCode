class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1] || !sea.hasShips(topRight, bottomLeft))
            return 0;
        else if (topRight == bottomLeft)
            return 1;
        int xmid = (topRight[0] + bottomLeft[0] + 1) / 2;
        int ymid = (topRight[1] + bottomLeft[1] + 1) / 2;
        return countShips(sea, topRight, {{xmid, ymid}}) 
            + countShips(sea, {xmid - 1, topRight[1]}, {bottomLeft[0], ymid})
            + countShips(sea, {topRight[0], ymid - 1}, {xmid, bottomLeft[1]})
            + countShips(sea, {xmid - 1, ymid - 1}, bottomLeft);
    }
};