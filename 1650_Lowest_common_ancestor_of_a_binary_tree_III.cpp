class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> parents;
        while (true) {
            if (p) {
                if (parents.find(p) != parents.end())
                    return p;
                parents.insert(p);
                p = p->parent;
            }
            if (q) {
                if (parents.find(q) != parents.end())
                    return q;
                parents.insert(q);
                q = q->parent;
            }
        }
        return NULL;
    }
};