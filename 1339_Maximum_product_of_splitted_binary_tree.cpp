#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        ll ans = 0;
        unordered_map<TreeNode*, ll> sumOfNodes;
        explore(0, root, sumOfNodes, ans);
        return ans % M;
    }
    
    void explore(ll prev, TreeNode* root, unordered_map<TreeNode*, ll>& sumOfNodes, ll& ans) {
        if (!root)
            return;
        ans = max(ans, sums(root->left, sumOfNodes) * (prev + root->val + sums(root->right, sumOfNodes)));
        ans = max(ans, sums(root->right, sumOfNodes) * (prev + root->val + sums(root->left, sumOfNodes)));
        explore(prev + root->val + sums(root->right, sumOfNodes), root->left, sumOfNodes, ans);
        explore(prev + root->val + sums(root->left, sumOfNodes), root->right, sumOfNodes, ans);
    }
    
    ll sums(TreeNode* root, unordered_map<TreeNode*, ll>& sumOfNodes) {
        if (!root)
            return 0;
        if (sumOfNodes.find(root) != sumOfNodes.end())
            return sumOfNodes[root];
        sumOfNodes[root] = root->val + sums(root->left, sumOfNodes) + sums(root->right, sumOfNodes);
        return sumOfNodes[root];
    }
};