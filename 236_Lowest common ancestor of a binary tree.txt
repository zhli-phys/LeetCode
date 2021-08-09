class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, bool> dp_p;
        unordered_map<TreeNode*, bool> dp_q;
        return ancester(root, p, q, dp_p, dp_q);
    }
    
    TreeNode* ancester(TreeNode* root, TreeNode* p, TreeNode* q, 
                       unordered_map<TreeNode*, bool>& dp_p, unordered_map<TreeNode*, bool>& dp_q) {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        else if ((contain(root->left, p, dp_p) && contain(root->right, q, dp_q))
                 || (contain(root->left, q, dp_q) && contain(root->right, p, dp_p)))
            return root;
        else if (!contain(root->left, p, dp_p))
            return ancester(root->right, p, q, dp_p, dp_q);
        else
            return ancester(root->left, p, q, dp_p, dp_q);
    }
    
    bool contain(TreeNode* root, TreeNode* p, unordered_map<TreeNode*, bool>& dp) {
        if (!root)
            return false;
        if (dp.find(root) != dp.end())
            return dp[root];
        if (root == p) 
            dp[root] = true;
        else
            dp[root] = contain(root->left, p, dp) || contain(root->right, p, dp);
        return dp[root];
    }
};















class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<unordered_map<TreeNode*, bool>> presence(2);
        return lowestCommonAncestor(root, p, q, presence);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, 
                                    vector<unordered_map<TreeNode*, bool>>& presence) {
        if (containp(root->left, p, q, presence) && containq(root->left, p, q, presence))
            return lowestCommonAncestor(root->left, p, q, presence);
        if (containp(root->right, p, q, presence) && containq(root->right, p, q, presence))
            return lowestCommonAncestor(root->right, p, q, presence);
        else
            return root;
    }
    
    bool containp(TreeNode* root, TreeNode* p, TreeNode* q,
                 vector<unordered_map<TreeNode*, bool>>& presence) {
        if (!root)
            return false;
        if (presence[0].find(root) != presence[0].end())
            return presence[0][root];
        if (root == p || containp(root->left, p, q, presence) || containp(root->right, p, q, presence)) {
            presence[0][root] = true;
            return true;
        }
        else {
            presence[0][root] = false;
            return false;
        }
    }
    
    bool containq(TreeNode* root, TreeNode* p, TreeNode* q,
                 vector<unordered_map<TreeNode*, bool>>& presence) {
        if (!root)
            return false;
        if (presence[1].find(root) != presence[1].end())
            return presence[1][root];
        if (root == q || containq(root->left, p, q, presence) || containq(root->right, p, q, presence)) {
            presence[1][root] = true;
            return true;
        }
        else {
            presence[1][root] = false;
            return false;
        }
    }
};














class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, bool> pparents;
        unordered_map<TreeNode*, bool> qparents;
        while (true) {
            if (containp(root->left, p, pparents) && containq(root->left, q, qparents))
                root = root->left;
            else if (containp(root->right, p, pparents) && containq(root->right, q, qparents))
                root = root->right;
            else
                return root;
        }
    }
    
    bool containp(TreeNode* root, TreeNode* p, unordered_map<TreeNode*, bool>& pparents) {
        if (!root)
            return false;
        if (pparents.find(root) != pparents.end())
            return pparents[root];
        if (root == p || containp(root->left, p, pparents) || containp(root->right, p, pparents)) {
            pparents[root] = true;
            return true;
        }
        else {
            pparents[root] = false;
            return false;
        }
    }
    
    bool containq(TreeNode* root, TreeNode* q, unordered_map<TreeNode*, bool>& qparents) {
        if (!root)
            return false;
        if (qparents.find(root) != qparents.end())
            return qparents[root];
        if (root == q || containp(root->left, q, qparents) || containp(root->right, q, qparents)) {
            qparents[root] = true;
            return true;
        }
        else {
            qparents[root] = false;
            return false;
        }
    }
};