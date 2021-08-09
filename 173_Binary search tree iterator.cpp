/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : root(root), prev(NULL) {
    }
    
    /** @return the next smallest number */
    int next() {
        int ans; 
        next(root, ans);
        return ans;
    }
    
    bool next(TreeNode* node, int& ans) {
        if (!node)
            return false;
        if (!prev || node->val > prev->val) {
            if (next(node->left, ans))
                return true;
            else {
                prev = node;
                ans = node->val;
                return true;
            }
        }
        return next(node->right, ans);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return hasNext(root);
    }
    
    bool hasNext(TreeNode* node) {
        if (!node)
            return false;
        if (!prev || node->val > prev->val) {
            return true;
        }
        return hasNext(node->right);
    }
    
private:
    TreeNode* root;
    TreeNode* prev;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

















/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : root(root){
        push_left(root);
    }
    
    void push_left(TreeNode* node) {
        while (node) {
            sk.push(node);
            node = node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int ans = sk.top()->val;
        TreeNode* temp = sk.top();
        sk.pop();
        push_left(temp->right);
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sk.empty();
    }
    
private:
    TreeNode* root;
    stack<TreeNode*> sk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */