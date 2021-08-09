class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int curr_x = 0;
        int curr_y = 0;
        int curr_z = 0;
        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                curr_x = max(curr_x, triplet[0]);
                curr_y = max(curr_y, triplet[1]);
                curr_z = max(curr_z, triplet[2]);
                if (curr_x == target[0] && curr_y == target[1] && curr_z == target[2])
                    return true;
            }
        }
        return false;
    }
};