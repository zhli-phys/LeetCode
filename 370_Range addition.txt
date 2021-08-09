//O(n + k) 32 ms 59%; O(n) 16.4 MB 81%
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        for (auto& update : updates) {
            arr[update[0]] += update[2];
            if (update[1] < length - 1)
                arr[update[1]+1] -= update[2];
        }
        for (int i = 1; i < length; ++i)
            arr[i] += arr[i-1];
        return arr;
    }
};