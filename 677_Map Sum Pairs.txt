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

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (mp.find(key) == mp.end()) {
            mp[key] = val;
            root.add(key, val);
        }
        else {
            root.add(key, val - mp[key]);
            mp[key] = val;
        }
    }
    
    int sum(string prefix) {
        return root.sum(prefix);
    }
    
private:
    unordered_map<string, int> mp;
    Trie root;
};


















class MapSum {
public:
    /** Initialize your data structure here. */
    
    struct Node {
        int val;
        Node* childs[26];
        Node(int val = 0) : val(val) {
            for (int i = 0; i < 26; i++)
                 childs[i] = NULL;
        }
    };
    
    MapSum() {
        root = new Node();
    }
    
    ~MapSum() {
        erase(root);
    }
    
    void erase(Node* root) {
        if (!root)
            return;
        for (int i = 0; i < 26; i++)
            erase(root->childs[i]);
        delete root;
    }
    
    void insert(string key, int val) {
        Node* curr = root;
        for (char ch : key) {
            if (!curr->childs[ch-'a']) 
                curr->childs[ch-'a'] = new Node();
            curr = curr->childs[ch-'a'];
        }
        curr->val = val;
    }
    
    int sum(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            if (!curr->childs[ch-'a'])
                return 0;
            curr = curr->childs[ch-'a'];
        }
        return sum(curr);
    }
    
    int sum(Node* root) {
        if (!root)
            return 0;
        int ans = root->val;
        for (int i = 0; i < 26; i++)
            ans += sum(root->childs[i]);
        return ans;
    }
    
private:
    Node* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */