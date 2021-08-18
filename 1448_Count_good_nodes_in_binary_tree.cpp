class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        countNodes(root, root->val, count);
        return count;
    }
    
    void countNodes(TreeNode* curr, int prevMax, int& count) {
        if (!curr)
            return;
        if (curr->val >= prevMax) {
            ++count;
            prevMax = curr->val;
        }
        countNodes(curr->left, prevMax, count);
        countNodes(curr->right, prevMax, count);
    }
};