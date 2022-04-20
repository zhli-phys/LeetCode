class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            sk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto curr = sk.top();
        sk.pop();
        auto node = curr->right;
        while (node) {
            sk.push(node);
            node = node->left;
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !sk.empty();
    }
    
private:
    stack<TreeNode*> sk;
};