class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> mp;
        return cloneGraph(node, mp);
    }
    
    Node* cloneGraph(Node* node, unordered_map<int, Node*>& mp) {
        if (mp.find(node->val) != mp.end())
            return mp[node->val];
        Node* node_copy = new Node(node->val);
        mp[node->val] = node_copy;
        for (Node* neighbor : node->neighbors) 
            node_copy->neighbors.push_back(cloneGraph(neighbor, mp));
        return node_copy;
    }
};