//map; lower rating to higher rating; 80 ms 5%; 31.8 MB 6%
class Solution {
public:
    int candy(vector<int>& ratings) {
        map<int, vector<int>> pos;
        int n = ratings.size();
        for (int i = 0; i < n; ++i) 
            pos[ratings[i]].push_back(i);
        vector<int> candies(n, 1);
        for (auto it = pos.begin(); it != pos.end(); ++it) {
            for (int p : it->second) {
                if (p > 0 && ratings[p] > ratings[p-1])
                    candies[p] = max(candies[p], candies[p-1] + 1);
                if (p < n - 1 && ratings[p] > ratings[p+1])
                    candies[p] = max(candies[p], candies[p+1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};







//vector; lower rating to higher rating; 44 ms 12%; 24.8 MB 6%
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> pos(*max_element(ratings.begin(), ratings.end()) + 1);
        int n = ratings.size();
        for (int i = 0; i < n; ++i) 
            pos[ratings[i]].push_back(i);
        vector<int> candies(n, 1);
        for (auto& vec : pos) {
            for (int p : vec) {
                if (p > 0 && ratings[p] > ratings[p-1])
                    candies[p] = max(candies[p], candies[p-1] + 1);
                if (p < n - 1 && ratings[p] > ratings[p+1])
                    candies[p] = max(candies[p], candies[p+1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};












//maximum of forward and backward; 16 ms 93%; 18.3 MB 21%
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> forward(n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                forward[i] = forward[i-1] + 1;
        vector<int> backward(n, 1);
        for (int i = n - 2; i >= 0; --i) 
            if (ratings[i] > ratings[i+1])
                backward[i] = backward[i+1] + 1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += max(forward[i], backward[i]);
        return ans;
    }
};