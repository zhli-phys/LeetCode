using ll = long long;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        ll ans = 1;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int m = q.size();
            ll leftPos = -1;
            for (int i = 0; i < m; ++i) {
                TreeNode* curr = q.front().first;
                ll currPos = q.front().second;
                q.pop();
                if (curr->left) {
                    if (leftPos < 0) {
                        leftPos = 2 * currPos;
                        q.push({curr->left, 0});
                    }
                    else {
                        ll pos = 2 * currPos - leftPos;
                        ans = max(ans, pos + 1); 
                        q.push({curr->left, pos});
                    }
                }
                if (curr->right) {
                    if (leftPos < 0) {
                        leftPos = 2 * currPos + 1;
                        q.push({curr->right, 0});
                    }
                    else {
                        ll pos = 2 * currPos + 1 - leftPos;
                        ans = max(ans, pos + 1); 
                        q.push({curr->right, pos});
                    }
                }
            }
        }
        return ans;
    }
};