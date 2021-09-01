class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delSet;
        for (int num : to_delete)
            delSet.insert(num);
        unordered_set<TreeNode*> nodes;
        nodes.insert(root);
        del(root, NULL, 0, delSet, nodes);
        vector<TreeNode*> ans;
        for (auto it = nodes.begin(); it != nodes.end(); ++it) 
            ans.push_back(*it);
        return ans;
    }
    
    void del(TreeNode* curr, TreeNode* parent, bool leftChild, 
             unordered_set<int>& delSet, unordered_set<TreeNode*>& nodes) {
        if (!curr)
            return;
        if (delSet.find(curr->val) != delSet.end()) {
            nodes.erase(curr);
            if (parent) {
                if (leftChild)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            if (curr->left) {
                nodes.insert(curr->left); 
                del(curr->left, NULL, 0, delSet, nodes);
            }                            
            if (curr->right) {
                nodes.insert(curr->right);
                del(curr->right, NULL, 0, delSet, nodes);
            }                
        }
        else {
            if (curr->left)
                del(curr->left, curr, 1, delSet, nodes);
            if (curr->right)
                del(curr->right, curr, 0, delSet, nodes);
        }
    }
};