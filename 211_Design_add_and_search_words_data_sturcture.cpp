struct TrieNode {
    bool presence;
    vector<TrieNode*> children;
    
    TrieNode(bool presence = false) : presence(presence), children(26, nullptr) { }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto curr = root;
        for (char ch : word) {
            if (!curr->children[ch-'a'])
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->presence = true;
    }
    
    bool search(string word) {
        return search(0, root, word);
    }
    
    bool search(int i, TrieNode* curr, const string& word) {
        if (!curr)
            return false;
        if (i == word.size())
            return curr->presence;
        if (word[i] != '.')
            return search(i+1, curr->children[word[i]-'a'], word);
        else {
            for (int next = 0; next < 26; ++next) {
                if (search(i+1, curr->children[next], word))
                    return true;
            }
            return false;
        }
    } 
        
private:
    TrieNode* root;
};