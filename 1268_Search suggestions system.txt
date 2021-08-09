//use trie, 204 ms 28%, 86.2 MB 37%
struct TrieNode {
    bool present;
    vector<TrieNode*> children;
    TrieNode() : present(false), children(26, NULL) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        del(root);
    }
    
    void del(TrieNode* curr) {
        if (!curr)
            return;
        for (int i = 0; i < 26; ++i)
            del(curr->children[i]);
        delete curr;
    }
    
    void insert(const string& s) {
        TrieNode* curr = root;
        for (char ch : s) {
            if (!curr->children[ch-'a'])
                curr->children[ch-'a'] = new TrieNode();
            curr = curr->children[ch-'a'];
        }
        curr->present = true;
    }
    
    vector<string> firstThree(string s) {
        vector<string> output;
        TrieNode* curr = root;
        for (char ch : s) {
            curr = curr->children[ch-'a'];
            if (!curr)
                return output;
        }
        search(curr, output, s);
        return output;
    }
    
    void search(TrieNode* curr, vector<string>& output, string& s) {
        if (curr->present) {
            output.push_back(s);
            if (output.size() == 3)
                return;
        }            
        for (int i = 0; i < 26; ++i) {
            if (curr->children[i]) {
                s.push_back('a' + i);
                search(curr->children[i], output, s);
                s.pop_back();
                if (output.size() == 3)
                    return;
            }
        }
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie words;
        vector<vector<string>> ans;
        for (auto&& product : products)
            words.insert(product);
        size_t n = searchWord.size();
        for (size_t i = 1; i <= n; ++i) 
            ans.push_back(words.firstThree(searchWord.substr(0, i)));
        return ans;
    }
};








//use hash table, 608 ms 12%, 122.6 MB 27%
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, set<string>> mp;
        for (auto&& product : products) {
            size_t n = product.size();
            for (size_t i = 1; i <= n; ++i)
                mp[product.substr(0, i)].insert(product);
        }
        vector<vector<string>> ans;
        size_t n = searchWord.size();
        for (size_t i = 1; i <= n; ++i) {
            vector<string> curr;
            auto it = mp.find(searchWord.substr(0, i));
            if (it != mp.end()) {
                for (auto inner_it = it->second.begin(); inner_it != it->second.end(); ++inner_it) {
                    curr.push_back(*inner_it);
                    if (curr.size() == 3)
                        break;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};