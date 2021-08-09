struct TrieNode {
    int val;
    vector<TrieNode*> children;
    TrieNode(int val = 0) : val(val), children(26, NULL) { }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        erase(root);
    }
    
    void erase(TrieNode* curr) {
        if (!curr)
            return;
        for (int i = 0; i < 26; ++i)
            erase(curr->children[i]);
        delete curr;
    }
    
    int sum(const string& prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children[ch-'a'])
                return 0;
            else 
                curr = curr->children[ch-'a'];
        }
        return curr->val;
    }
    
    void add(const string& key, int val) {
        TrieNode* curr = root;
        for (char ch : key) {
            if (!curr->children[ch-'a'])
                curr->children[ch-'a'] = new TrieNode(val);
            else 
                curr->children[ch-'a']->val += val;
            curr = curr->children[ch-'a'];
        }
    }
    
private:
    TrieNode* root;
};