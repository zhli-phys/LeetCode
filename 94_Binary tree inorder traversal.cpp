class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        inorderTraversal(root, sol);
        return sol;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& sol) {
        if (root) {
            inorderTraversal(root->left, sol);
            sol.push_back(root->val);
            inorderTraversal(root->right, sol);
        }
    }
};





class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        stack<TreeNode*> nodes;
        TreeNode* current = root;
        while(current) {
            nodes.push(current);
            current = current->left;
        }
        while(!nodes.empty()) {
            TreeNode* front = nodes.top();
            sol.push_back(front->val);
            nodes.pop();
            front = front->right;
            while(front) {
                nodes.push(front);
                front = front->left;
            }
        }
        return sol;
    }
};