class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> money;
        return rob(root, money);
    }
    
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& money) {
        if (!root)
            return 0;
        if (money.find(root) != money.end())
            return money[root];
        int curr = root->val;
        if (root->left)
            curr = curr + rob(root->left->left, money) + rob(root->left->right, money);
        if (root->right)
            curr = curr + rob(root->right->left, money) + rob(root->right->right, money);
        int childs = rob(root->left, money) + rob(root->right, money);
        int ans = max(curr, childs);
        money[root] = ans;
        return ans;
    }
};