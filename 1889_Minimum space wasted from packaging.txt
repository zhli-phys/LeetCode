#define M 1000000007
using ll = long long;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        int m = boxes.size();
        ll min_waste_space = -1;
        sort(packages.begin(), packages.end());
        ll sum = accumulate(packages.begin(), packages.end(), 0ll);
        for (auto&& box : boxes) {
            sort(box.begin(), box.end());
            if (box.back() < packages.back())
                continue;
            ll curr_waste_space = 0;
            auto prev_it = packages.begin();
            for (int box_size : box) {
                auto it = upper_bound(packages.begin(), packages.end(), box_size);
                curr_waste_space += static_cast<ll>(box_size) * (it - prev_it);
                prev_it = it;
            }
            curr_waste_space -= sum;
            if (min_waste_space == -1)
                min_waste_space = curr_waste_space;
            else
                min_waste_space = min(min_waste_space, curr_waste_space);
        }
        return min_waste_space % M;
    }
};