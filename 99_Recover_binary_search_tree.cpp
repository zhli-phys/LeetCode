class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(root, vec);
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        int n = vec.size();
        for (int i = 0; i < n - 1; ++i) {
            if (vec[i]->val > vec[i+1]->val) {
                first = vec[i];
                break;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (vec[i]->val < vec[i-1]->val) {
                second = vec[i];
                break;
            }
        }
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& vec) {
        if (!root)
            return;
        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }
};