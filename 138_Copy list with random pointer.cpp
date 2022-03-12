class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;
        auto newHead = new Node(head->val);
        auto curr = head;
        auto newCurr = newHead;
        mp[curr] = newCurr;
        while (curr->next) {
            newCurr->next = new Node(curr->next->val);
            curr = curr->next;
            newCurr = newCurr->next;
            mp[curr] = newCurr;
        }
        curr = head;
        newCurr = newHead;
        while (curr) {
            newCurr->random = mp[curr->random];
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};














class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        vector<Node*> original_nodes;
        unordered_map<Node*, int> node_indices;
        int len = 0;
        while(head) {
            original_nodes.push_back(head);
            node_indices[head] = len;
            head = head->next;
            len++;
        }
        original_nodes.push_back(NULL);
        node_indices[NULL] = len;
        vector<Node*> new_nodes(len + 1);
        for (int i = 0; i < len; i++) 
            new_nodes[i] = new Node(original_nodes[i]->val);
        new_nodes[len] = NULL;
        for (int i = 0; i < len; i++) {
            new_nodes[i]->next = new_nodes[i + 1];
            new_nodes[i]->random = new_nodes[node_indices[original_nodes[i]->random]];
        }
        return new_nodes[0];
    }
};