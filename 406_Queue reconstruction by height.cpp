class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (ans[j].empty()) {
                    if (count == people[i][1]) {
                        ans[j] = people[i];
                        break;
                    }
                    else
                        count++;
                }
                else if (ans[j][0] == people[i][0])
                    count++;
            }
        }
        return ans;
    }
};