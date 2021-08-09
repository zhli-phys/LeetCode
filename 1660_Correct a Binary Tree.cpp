/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<int> visited;
        TreeNode* target = NULL;
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root->val);
        while(!q.empty()) {
            int n = q.size();
            bool flag = false;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if (curr->right) {
                    if (visited.count(curr->right->val)) {
                        target = curr;
                        flag = true;
                        break;
                    }
                    else {
                        q.push(curr->right);
                        visited.insert(curr->right->val);
                    }
                }
            }
            if (flag)
                break;
        }
        remove(root, target);
        return root;
    }
    
    void remove(TreeNode* root, TreeNode* target) {
        if (!root)
            return;
        if (root->left == target)
            root->left = NULL;
        if (root->right == target)
            root->right = NULL;
        remove(root->left, target);
        remove(root->right, target);
    }
};