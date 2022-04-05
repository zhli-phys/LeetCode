class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> left;
        left.push_back(0);
        for (int i = 1; i < n; ++i) {
            if (height[i] > height[left.back()])
                left.push_back(i);
        }
        vector<int> right;
        right.push_back(n-1);
        for (int i = n - 2; i >= 0; --i) {
            if (height[i] > height[right.back()])
                right.push_back(i);
        }
        int i = left.size() - 1;
        int j = right.size() - 1;
        int ans = height[left[i]] * (right[j] - left[i]);
        while (i > 0 || j > 0) {
            if (i == 0 || (j != 0 && height[left[i-1]] <= height[right[j-1]])) {
                --j;                
            }
            else {
                --i;                
            }
            ans = max(ans, min(height[left[i]], height[right[j]]) * (right[j] - left[i]));
        }
        return ans;
    }
};










class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (true) {
            if (left >= right)
                break;
            maxarea = max(maxarea, (right - left) * min(height[left], height[right]));
            if (height[left] >= height[right])
                right--;
            else
                left++;
        }
        return maxarea;
    }
};