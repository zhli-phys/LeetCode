class Solution {
public:
    int trap(vector<int>& height) {
        int max_i = max_element(height.begin(), height.end()) - height.begin();
        int current = 0;
        int water = 0;
        for (int i = 0; i < max_i; i++) {
            int temp = height[i];
            if (temp < current) 
                water += current - temp;
            else 
                current = temp;
        }
        current = 0;
        for (int i = height.size() - 1; i > max_i; i--) {
            int temp = height[i];
            if (temp < current)
                water += current - temp;
            else
                current = temp;
        }
        return water;
    }
};










class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftHeight = 0;
        int rightHeight = 0;
        int water = 0;
        while (left <= right) {
            if (leftHeight < rightHeight) {
                if (height[left] < leftHeight)
                    water += leftHeight - height[left];
                else
                    leftHeight = height[left];
                ++left;
            }
            else {
                if (height[right] < rightHeight)
                    water += rightHeight - height[right];
                else
                    rightHeight = height[right];
                --right;
            }
        }
        return water;
    }
};