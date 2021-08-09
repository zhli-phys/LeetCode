class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* temp = nodes.front();
            if (temp) {
                nodes.push(temp->left);
                nodes.push(temp->right);
                ans += (to_string(temp->val) + ',');
            }
            else 
                ans += ',';
            nodes.pop();
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        queue<TreeNode*> nodes;
        size_t pos = data.find(',');
        TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
        nodes.push(root);
        pos++;
        size_t n = data.size();
        while (pos < n) {
            TreeNode* curr = nodes.front();
            size_t next = data.find(',', pos);
            if (next != pos) {
                curr->left = new TreeNode(stoi(data.substr(pos, next - pos)));
                nodes.push(curr->left);
            }
            pos = next + 1;
            next = data.find(',', pos);
            if (next != pos) {
                curr->right = new TreeNode(stoi(data.substr(pos, next - pos)));
                nodes.push(curr->right);
            }
            pos = next + 1;
            nodes.pop();
        }
        return root;
    }
};