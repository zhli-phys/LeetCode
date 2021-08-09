//0 ms, 14.8 MB
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> dist;
        bottom_up(root, target, dist);
        up_bottom(root, dist);
        vector<int> ans;
        for (auto it = dist.begin(); it != dist.end(); ++it) 
            if (it->second == k)
                ans.push_back(it->first->val);
        return ans;
    }
    
    int bottom_up(TreeNode* curr, TreeNode* target, unordered_map<TreeNode*, int>& dist) {
        if (!curr)
            return INT_MAX;
        if (dist.find(curr) != dist.end())
            return dist[curr];
        int left_dist = bottom_up(curr->left, target, dist);
        int right_dist = bottom_up(curr->right, target, dist);
        if (left_dist == INT_MAX && right_dist == INT_MAX)
            dist[curr] = INT_MAX;
        else 
            dist[curr] = min(left_dist, right_dist) + 1;
        if (curr == target)
            dist[curr] = 0;
        return dist[curr];
    }
    
    void up_bottom(TreeNode* curr, unordered_map<TreeNode*, int>& dist) {
        if (!curr)
            return;
        if (curr->left)
            dist[curr->left] = min(dist[curr->left], dist[curr] + 1);
        up_bottom(curr->left, dist);
        if (curr->right)
            dist[curr->right] = min(dist[curr->right], dist[curr] + 1);
        up_bottom(curr->right, dist);
    }
};