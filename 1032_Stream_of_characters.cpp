struct TrieNode {
    bool presence;
    vector<TrieNode*> children;
    
    TrieNode(bool presence = false): presence(presence), children(26, nullptr) { }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        str.push_back(letter);
        return search();
    }
    
private:    
    void insert(const string& s) {
        auto curr = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            int pos = s[i] - 'a';
            if (!curr->children[pos])
                curr->children[pos] = new TrieNode();
            curr = curr->children[pos];
        }
        curr->presence = true;
    }
    
    bool search() {
        auto curr = root;
        for (int i = str.size() - 1; i >= 0; --i) {
            int pos = str[i] - 'a';
            if (!curr->children[pos])
                return false;
            curr = curr->children[pos];
            if (curr->presence)
                return true;
        }
        return false;
    }
    
    TrieNode* root;
    string str;
};












struct TrieNode {
    bool presence;
    vector<TrieNode*> children;
    
    TrieNode(bool presence = false): presence(presence), children(26, nullptr) { }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& word : words) {
            insert(word);
        }
        vec.reserve(2001);
        vec.push_back(root);
    }
    
    bool query(char letter) {
        int pos = letter - 'a';
        bool found = false;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i]->children[pos]) {
                vec[i] = vec[i]->children[pos];
                if (vec[i]->presence)
                    found = true;
            }
            else {
                swap(vec[i], vec.back());
                vec.pop_back();
                --i;
            }
        }
        vec.push_back(root);
        return found;
    }
    
private:    
    void insert(const string& s) {
        auto curr = root;
        for (char ch : s) {
            if (!curr->children[ch-'a'])
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->presence = true;
    }
    
    TrieNode* root;
    vector<TrieNode*> vec;
};