class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        return helper(0, n - 1, heights);
    }
    
    int helper(int i, int j, vector<int>& heights) {
        if (i > j)
            return 0;
        else if (i == j)
            return heights[i];
        int mid = (i + j) / 2;
        int ans = max(helper(i, mid - 1, heights), helper(mid + 1, j, heights));
        int left = mid - 1;
        int right = mid + 1;
        int currHeight = heights[mid];
        int curr = currHeight;
        ans = max(ans, curr);
        while (left >= i || right <= j) {
            if (left < i) {
                currHeight = min(currHeight, heights[right]);
                curr = currHeight * (right - left);
                ++right;
            }
            else if (right > j) {
                currHeight = min(currHeight, heights[left]);
                curr = currHeight * (right - left);
                --left;
            }
            else {
                if (heights[left] >= heights[right]) {
                    currHeight = min(currHeight, heights[left]);
                    curr = currHeight * (right - left);
                    --left;
                }
                else {
                    currHeight = min(currHeight, heights[right]);
                    curr = currHeight * (right - left);
                    ++right;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};













class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        return largestRectangleArea(heights, 0, heights.size());
    }
    
    int largestRectangleArea(vector<int>& heights, int left, int right) {
        if (left == right - 1)
            return heights[left];
        int middle = (left + right) / 2;
        int current_height = heights[middle];
        int left_i = middle;
        int right_i = middle + 1;
        int middle_area = heights[middle];
        while (true) {
            if (left_i == left && right_i == right) {
                middle_area = max(middle_area, (right_i - left_i) * current_height);
                break;
            }
            if (left_i == left) {
                int temp = heights[right_i];
                if (temp < current_height) {
                    middle_area = max(middle_area, (right_i - left_i) * current_height);
                    current_height = temp;
                }
                right_i++;
            }
            else if (right_i == right) {
                int temp = heights[left_i - 1];
                if (temp < current_height) {
                    middle_area = max(middle_area, (right_i - left_i) * current_height);
                    current_height = temp;
                }
                left_i--;
            }
            else {
                int height_left = heights[left_i - 1];
                int height_right = heights[right_i];
                if (height_left >= current_height)
                    left_i--;
                else if (height_right >= current_height)
                    right_i++;
                else {
                    middle_area = max(middle_area, (right_i - left_i) * current_height);
                    current_height = max(height_left, height_right);
                }
            }
        }
        int left_area = largestRectangleArea(heights, left, middle);
        int right_area = largestRectangleArea(heights, middle, right);
        int a[3] = { left_area, middle_area, right_area };
        return *max_element(a, a+3);
    }
};










class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ind;
        ind.push(-1);
        int max_area = 0;
        int len = heights.size();
        for (int i = 0; i < len; i++) {
            int temp = ind.top();
            while(temp >= 0 && heights[temp] >= heights[i]) {
                int h = heights[temp];
                ind.pop();
                temp = ind.top();
                max_area = max(max_area, (i - temp - 1) * h);
            }
            ind.push(i);
        }
        while(ind.size() > 1) {
            int last = ind.top();
            ind.pop();
            max_area = max(max_area, (len - ind.top() - 1) * heights[last]);
        }
        return max_area;
    }
};