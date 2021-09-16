class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 1);
        vector<int> down(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                up[i] = down[i-1] + 1;
                ans = max(ans, up[i]);
            }
            else if (arr[i] < arr[i-1]) {
                down[i] = up[i-1] + 1;
                ans = max(ans, down[i]);
            }
        }
        return ans;
    }
};








class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int up = 1;
        int down = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                up = down + 1;
                down = 1;
                ans = max(ans, up);
            }
            else if (arr[i] < arr[i-1]) {
                down = up + 1;
                up = 1;
                ans = max(ans, down);
            }
            else {
                up = 1;
                down = 1;
            }
        }
        return ans;
    }
};