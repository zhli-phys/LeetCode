class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelLen = q.size();
            vector<int> currLevel;
            for (int i = 0; i < levelLen; ++i) {
                auto curr = q.front();
                currLevel.push_back(curr->val);
                for (auto child : curr->children) {
                    if (child)
                        q.push(child);
                }
                q.pop();
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};