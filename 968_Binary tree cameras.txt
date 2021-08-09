class Solution {
public:
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        unordered_map<TreeNode*, int> dp_covered;
        return min_camera(root, dp, dp_covered);
    }
    
    int min_camera(TreeNode* curr, unordered_map<TreeNode*, int>& dp, 
                   unordered_map<TreeNode*, int>& dp_covered) {
        if (!curr)
            return 0;
        if (dp.find(curr) != dp.end())
            return dp[curr];
        int ans = 1 + min_camera_curr_covered(curr->left, dp, dp_covered) 
            + min_camera_curr_covered(curr->right, dp, dp_covered);
        if (curr->left) 
            ans = min(ans, 1 + min_camera(curr->right, dp, dp_covered) 
                      + min_camera_curr_covered(curr->left->left, dp, dp_covered)
                      + min_camera_curr_covered(curr->left->right, dp, dp_covered));
        if (curr->right)
            ans = min(ans, 1 + min_camera(curr->left, dp, dp_covered) 
                      + min_camera_curr_covered(curr->right->left, dp, dp_covered)
                      + min_camera_curr_covered(curr->right->right, dp, dp_covered));
        dp[curr] = ans;
        return ans;
    }
    
    int min_camera_curr_covered(TreeNode* curr, unordered_map<TreeNode*, int>& dp,
                                      unordered_map<TreeNode*, int>& dp_covered) {
        if (!curr)
            return 0;
        if (dp_covered.find(curr) != dp_covered.end())
            return dp_covered[curr];
        int ans = 1 + min_camera_curr_covered(curr->left, dp, dp_covered) 
            + min_camera_curr_covered(curr->right, dp, dp_covered);
        ans = min(ans, min_camera(curr->left, dp, dp_covered) + min_camera(curr->right, dp, dp_covered));
        dp_covered[curr] = ans;
        return ans;
    }
};

















//using "val" to save dp and dp_covered values
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (!root)
            return 0;
        if (root->val % 1000 > 0)
            return root->val % 1000;
        int ans = 1 + covered(root->left) + covered(root->right);
        if (root->left) 
            ans = min(ans, 1 + minCameraCover(root->right) + covered(root->left->left) + covered(root->left->right));
        if (root->right)
            ans = min(ans, 1 + minCameraCover(root->left) + covered(root->right->left) + covered(root->right->right));
        root->val += ans;
        return ans;
    }
    
    int covered(TreeNode* root) {
        if (!root)
            return 0;
        if (root->val / 1000 > 0)
            return root->val / 1000;
        int ans = 1 + covered(root->left) + covered(root->right);
        ans = min(ans, minCameraCover(root->left) + minCameraCover(root->right));
        root += (1000 * ans);
        return ans;
    }
};














\\greedy algorithm
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> covered;
        covered.insert(NULL);
        int cameras = 0;
        solve(root, NULL, covered, cameras);
        if (covered.find(root) == covered.end())
            ++cameras;
        return cameras;
    }
    
    void solve(TreeNode* curr, TreeNode* par, unordered_set<TreeNode*>& covered, int &cameras) {
        if (covered.find(curr) != covered.end())
            return;
        solve(curr->left, curr, covered, cameras);
        solve(curr->right, curr, covered, cameras);
        if (covered.find(curr->left) != covered.end() && covered.find(curr->right) != covered.end())
            return;
        ++cameras;
        covered.insert(curr);
        covered.insert(curr->left);
        covered.insert(curr->right);
        covered.insert(par);
    }
};













//use "val == 1" to stand for covered
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        solve(root, NULL, cameras);
        if (!root->val)
            ++cameras;
        return cameras;
    }
    
    void solve(TreeNode* curr, TreeNode* par, int &cameras) {
        if (!curr || curr->val)
            return;
        solve(curr->left, curr, cameras);
        solve(curr->right, curr, cameras);
        if ((!curr->left || curr->left->val) && (!curr->right || curr->right->val))
            return;
        ++cameras;
        curr->val = 1;
        if (curr->left) 
            curr->left->val = 1;
        if (curr->right)
            curr->right->val = 1;
        if (par)
            par->val = 1;
    }
};