class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int n1 = slots1.size();
        int n2 = slots2.size();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            int l1 = slots1[i][0];
            int r1 = slots1[i][1];
            int l2 = slots2[j][0];
            int r2 = slots2[j][1];
            if (r1 <= l2)
                ++i;
            else if (l1 >= r2)
                ++j;
            else if (min(r1, r2) - max(l1, l2) >= duration) 
                return {max(l1, l2), max(l1, l2) + duration};
            else if (r1 >= r2)
                ++j;
            else 
                ++i;
        }
        return vector<int>();
    }
};