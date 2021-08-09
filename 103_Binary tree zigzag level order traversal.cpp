/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode*> dq;
        bool direction = true;
        dq.push_back(root);
        while(!dq.empty()) {
            vector<int> vec;
            int n = dq.size();
            for (int i = 0; i < n; i++) {
                if (direction) {
                    TreeNode* curr = dq.front();
                    if (curr->left)
                        dq.push_back(curr->left);
                    if (curr->right)
                        dq.push_back(curr->right);
                    vec.push_back(curr->val);
                    dq.pop_front();
                }
                else {
                    TreeNode* curr = dq.back();
                    if (curr->right)
                        dq.push_front(curr->right);
                    if (curr->left)
                        dq.push_front(curr->left);
                    vec.push_back(curr->val);
                    dq.pop_back();
                }
            }
            ans.push_back(vec);
            direction = !direction;
        }
        return ans;
    }
};