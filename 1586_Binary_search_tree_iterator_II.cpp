class BSTIterator {
public:
    BSTIterator(TreeNode* root) : idx(-1) {
        inorder(root);
        n = nums.size();
    }
    
    bool hasNext() {
        return idx < n - 1;
    }
    
    int next() {
        return nums[++idx];
    }
    
    bool hasPrev() {
        return idx > 0;
    }
    
    int prev() {
        return nums[--idx];
    }
    
private:
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> nums;
    int idx;
    int n;
};