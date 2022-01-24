class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (!root)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                auto curr = q.front();
                q.pop();
                if (flag)
                    return curr;
                if (curr == u)
                    flag = true;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (flag)
                return nullptr;
        }
        return nullptr;
    }
};