class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) 
            return;
        queue<TreeNode*> nodes;
        build_queue(root, nodes);
        nodes.pop();
        while(!nodes.empty()) {
            root->left = NULL;
            root->right = nodes.front();
            root = root->right;
            nodes.pop();
        }
    }
    
    void build_queue(TreeNode* root, queue<TreeNode*>& nodes) {
        if(!root) 
            return;
        nodes.push(root);
        build_queue(root->left, nodes);
        build_queue(root->right, nodes);
    }
};










class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flat(root);
    }
    
    pair<TreeNode*, TreeNode*> flat(TreeNode* root) {
        if (root->left && root->right) {
            auto lp = flat(root->left);
            auto rp = flat(root->right);
            root->left = NULL;
            root->right = lp.first;
            lp.second->right = rp.first;
            return {root, rp.second};
        }
        else if (root->left) {
            auto lp = flat(root->left);
            root->left = NULL;
            root->right = lp.first;
            return {root, lp.second};
        }
        else if (root->right) {
            auto rp = flat(root->right);
            root->left = NULL;
            root->right = rp.first;
            return {root, rp.second};
        }
        else 
            return {root, root};
    }
};












class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
    
    pair<TreeNode*, TreeNode*> flat(TreeNode* root) {
        if (!root)
            return {NULL, NULL};
        auto lp = flat(root->left);
        auto rp = flat(root->right);
        root->left = NULL;
        if (lp.first) {
            root->right = lp.first;
            if (rp.first) {
                lp.second->right = rp.first;
                return {root, rp.second};
            }
            else 
                return {root, lp.second};
        }
        else if (rp.first) {
            root->right = rp.first;
            return {root, rp.second};
        }
        else 
            return {root, root};
    }
};















//O(1) space
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* curr = root->left;
                while (curr->right)
                    curr = curr->right;
                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};