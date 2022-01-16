class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> copyArr(arr);
        sort(copyArr.begin(), copyArr.end());
        int n = arr.size();
        unordered_map<int, int> rank;
        for (int i = 0; i < n; ++i) {
            if (rank.find(copyArr[i]) == rank.end())
                rank[copyArr[i]] = i;
        }
        int currMaxRank = -1;
        int currMax = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > currMax) {
                currMaxRank = rank[arr[i]];
                currMax = arr[i];
            }                
            else if (arr[i] == currMax)
                ++currMaxRank;
            if (currMaxRank <= i)
                ++ans;
        }
        return ans;
    }
};