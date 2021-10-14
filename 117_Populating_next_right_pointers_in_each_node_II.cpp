class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        while (head) {
            Node* nextHead = nullptr;
            Node* nextPrev = nullptr;
            Node* curr = head;
            while (curr) {
                if (curr->left) {
                   if (!nextHead) {
                       nextHead = curr->left;
                       nextPrev = nextHead;
                   }                      
                   else {
                       nextPrev->next = curr->left;
                       nextPrev = curr->left;
                   }
                } 
                if (curr->right) {
                   if (!nextHead) {
                       nextHead = curr->right;
                       nextPrev = nextHead;
                   }                      
                   else {
                       nextPrev->next = curr->right;
                       nextPrev = curr->right;
                   }
                } 
                curr = curr->next;
            }
            head = nextHead;
        }
        return root;
    }
};














class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* prev = q.front();
            if (prev->left)
                q.push(prev->left);
            if (prev->right)
                q.push(prev->right);
            q.pop();
            for (int i = 1; i < n; ++i) {
                Node* curr = q.front();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                q.pop();
                prev->next = curr;
                prev = curr;
            }
        }
        return root;
    }
};