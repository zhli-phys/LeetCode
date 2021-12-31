class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return max(diff(root->left, root->val, root->val), diff(root->right, root->val, root->val));
    }
    
    int diff(TreeNode* curr, int maxNum, int minNum) {
        if (!curr)
            return 0;
        int ans = max(abs(maxNum - curr->val), abs(minNum - curr->val));
        maxNum = max(maxNum, curr->val);
        minNum = min(minNum, curr->val);
        ans = max(ans, diff(curr->left, maxNum, minNum));
        ans = max(ans, diff(curr->right, maxNum, minNum));
        return ans;
    }
};












class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        unordered_map<TreeNode*, int> smallest;
        unordered_map<TreeNode*, int> largest;
        return helper(root, smallest, largest);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& smallest, unordered_map<TreeNode*, int>& largest) {
        if (!root)
            return 0;
        int ans = max(helper(root->left, smallest, largest), helper(root->right, smallest, largest));
        if (root->left) {
            int diff = root->val - small(root->left, smallest);
            diff = diff >= 0 ? diff : -diff;
            ans = max(ans, diff);
            diff = large(root->left, largest) - root->val;
            diff = diff >= 0 ? diff : -diff;
            ans = max(ans, diff);
        }
        if (root->right) {
            int diff = root->val - small(root->right, smallest);
            diff = diff >= 0 ? diff : -diff;
            ans = max(ans, diff);
            diff = large(root->right, largest) - root->val;
            diff = diff >= 0 ? diff : -diff;
            ans = max(ans, diff);
        }
        return ans;
    }
    
    int small(TreeNode* root, unordered_map<TreeNode*, int>& smallest) {
        if (smallest.count(root))
            return smallest[root];
        int ans = root->val;
        if (root->left)
            ans = min(ans, small(root->left, smallest));
        if (root->right)
            ans = min(ans, small(root->right, smallest));
        smallest[root] = ans;
        return ans;
    }
    
    int large(TreeNode* root, unordered_map<TreeNode*, int>& largest) {
        if (largest.count(root))
            return largest[root];
        int ans = root->val;
        if (root->left)
            ans = max(ans, large(root->left, largest));
        if (root->right)
            ans = max(ans, large(root->right, largest));
        largest[root] = ans;
        return ans;
    }
};












class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        helper(root, root->val, root->val, ans);
        return ans;
    }
    
    void helper(TreeNode* root, int Max, int Min, int& ans) {
        if (!root)
            return;
        ans = max(ans, Max - root->val);
        ans = max(ans, root->val - Min);
        Max = max(Max, root->val);
        Min = min(Min, root->val);
        helper(root->left, Max, Min, ans);
        helper(root->right, Max, Min, ans);
    }
};









class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    
    int helper(TreeNode* root, int Max, int Min) {
        if (!root)
            return Max - Min;
        Max = max(Max, root->val);
        Min = min(Min, root->val);
        int left = helper(root->left, Max, Min);
        int right = helper(root->right, Max, Min);
        return max(left, right);
    }
};