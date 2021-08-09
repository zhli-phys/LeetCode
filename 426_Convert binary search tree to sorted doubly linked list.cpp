//4 ms 92%, 7.7 MB 35%, use stack
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        Node* curr = root;
        stack<Node*> sk;
        while (curr) {
            sk.push(curr);
            curr = curr->left;
        }
        root = sk.top();
        while (!sk.empty()) {
            curr = sk.top();
            sk.pop();
            Node* next = curr->right;
            while (next) {
                sk.push(next);
                next = next->left;
            }
            if (!sk.empty()) {
                curr->right = sk.top();
                sk.top()->left = curr;
            }
            else {
                curr->right = root;
                root->left = curr;
            }
        }
        return root;
    }
};