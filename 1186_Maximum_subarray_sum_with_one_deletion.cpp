class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int currSum = arr[0];
        int preMin = 0;
        int preMin1 = 0;
        int n = arr.size();
        int maxSum = arr[0];
        for (int i = 1; i < n; ++i) {
            preMin1 = min(preMin1, preMin + arr[i - 1]);  
            preMin = min(currSum, preMin);             
            currSum += arr[i];
            maxSum = max(maxSum, currSum - preMin1);                                 
        }
        return maxSum;
    }
};