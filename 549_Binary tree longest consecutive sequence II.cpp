//12 ms 79%; 23 MB 52%
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 1;
        length(root, ans);
        return ans;
    }
    
    pair<int, int> length(TreeNode* root, int& ans) {
        if (!root)
            return {0, 0};
        auto leftPair = length(root->left, ans);
        auto rightPair = length(root->right, ans);
        pair<int, int> curr{1, 1};
        if (root->left) {
            if (root->left->val == root->val - 1) 
                curr.first = leftPair.first + 1;
            else if (root->left->val == root->val + 1)
                curr.second = leftPair.second + 1;
        }
        if (root->right) {
            if (root->right->val == root->val - 1) 
                curr.first = max(curr.first, rightPair.first + 1);
            else if (root->right->val == root->val + 1)
                curr.second = max(curr.second, rightPair.second + 1);
        }
        ans = max(ans, curr.first + curr.second - 1);
        return curr;
    }
};










//hashmap; 20 ms 40%; 24.1 MB 30%
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        vector<unordered_map<TreeNode*, int>> mp(2);
        return longest(root, mp);
    }
    
    int longest(TreeNode* root, vector<unordered_map<TreeNode*, int>>& mp) {
        if (!root)
            return 0;
        int ans = max(longest(root->left, mp), longest(root->right, mp));
        ans = max(ans, length(root->left, root->val-1, 0, mp) + length(root->right, root->val+1, 1, mp) + 1);
        ans = max(ans, length(root->left, root->val+1, 1, mp) + length(root->right, root->val-1, 0, mp) + 1);
        return ans;
    }
    
    int length(TreeNode* root, int target, int flag, vector<unordered_map<TreeNode*, int>>& mp) {
        if (!root || root->val != target)
            return 0;
        if (mp[flag].find(root) != mp[flag].end())
            return mp[flag][root];
        target += 2*flag-1;
        int ans = max(length(root->left, target, flag, mp), length(root->right, target, flag, mp)) + 1;
        mp[flag][root] = ans;
        return ans;
    }
};








