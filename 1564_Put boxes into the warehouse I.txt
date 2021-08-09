class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int prev = INT_MAX;
        for (auto&& i : warehouse) {
            i = min(prev, i);
            prev = i;
        }
        sort(boxes.begin(), boxes.end());
        int count = 0;
        int right = warehouse.size() - 1;
        for (auto&& box : boxes) {
            while (right >= 0 && warehouse[right] < box)
                --right;
            if (right < 0)
                break;
            ++count;
            --right;
        }
        return count;
    }
};