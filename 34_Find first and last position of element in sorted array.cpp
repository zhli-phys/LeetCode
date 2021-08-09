class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2);
        sol[0] = -1;
        sol[1] = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            int temp = nums[middle];
            if (temp == target) {
                int left1 = left;
                int right1 = middle;               
                while (left1 <= right1) {
                    if (nums[left1] == target) {
                        sol[0] = left1;
                        break;
                    }
                    int middle1 = (left1 + right1) / 2;
                    if (nums[middle1] < target) 
                        left1 = middle1 + 1;
                    else 
                        right1 = middle1;   
                }
                left1 = middle;
                right1 = right;
                while (left1 <= right1) {
                    if (nums[right1] == target) {
                        sol[1] = right1;
                        break;
                    }
                    int middle1 = (left1 + right1 + 1) / 2;
                    if (nums[middle1] > target)
                        right1 = middle1 - 1;
                    else
                        left1 = middle1;
                }
                break;
            }
            if (temp > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return sol;
    }
};







class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0;
        int right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
            if (left == right && right < nums.size() && nums[right] == target)
                ans[0] = right;
        }
        left = 0;
        right = nums.size();
        while(left < right) {
            if (right == left + 1) {
                if (nums[left] == target)
                    ans[1] = left;
                break;
            }
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            else
                left = mid;
        }
        return ans;
    }
};











//More robust and more symmetric solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0;
        int right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else {
                ans[0] = mid;
                right = mid;
            }
        }
        left = 0;
        right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else {
                ans[1] = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};