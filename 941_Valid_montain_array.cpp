class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return false;
        if (arr[1] <= arr[0] || arr[n-1] >= arr[n-2])
            return false;
        bool increasing = true;
        for (int i = 1; i < n; ++i) {
            if (increasing) {
                if (arr[i] == arr[i-1])
                    return false;
                else if (arr[i] < arr[i-1])
                    increasing = false;
            }
            else {
                if (arr[i] >= arr[i-1])
                    return false;
            }
        }
        return true;
    }
};