class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        queue<TreeNode*> nodes;
        if (root)
            nodes.push(root);
        while (!nodes.empty()) {
            vector<int> temp;
            int len = nodes.size();
            for (int i = 0; i < len; i++) {
                TreeNode* current = nodes.front();
                temp.push_back(current->val);
                if (current->left)
                    nodes.push(current->left);
                if (current->right)
                    nodes.push(current->right);
                nodes.pop();
            }
            sol.push_back(temp);
        }
        return sol;
    }
};