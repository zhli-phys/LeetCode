class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root)
            return root;
        Node* ans = new Node(root->val);
        for (Node* child : root->children) 
            ans->children.push_back(cloneTree(child));
        return ans;
    }
};