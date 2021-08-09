class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = n - 1; i >= 0; --i) {
            int m = words[i].size();
            for (int j = 0; j < m; ++j) {
                pre[words[i].substr(0, j+1)].push_back(i);
                suf[words[i].substr(m-j-1)].insert(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        auto& vec = pre[prefix];
        auto& st = suf[suffix];
        for (auto i : vec) {
            if (st.find(i) != st.end())
                return i;
        }
        return -1;
    }
    
private:
    unordered_map<string, vector<int>> pre;
    unordered_map<string, unordered_set<int>> suf;
};














class TrieNode {
public:
    friend class WordFilter;
    TrieNode(int weight) : weight(weight), children(27, NULL) { }
    ~TrieNode() {
        for (auto child : children) {
            if (child)
                delete child;
        }
    }   
    
private:
    int weight;
    vector<TrieNode*> children;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode(-1);
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int m = words[i].size();
            for (int j = 0; j < m; ++j) {
                string s = words[i].substr(j) + '#' + words[i];
                int l = s.size();
                TrieNode* curr = root;
                for (int k = 0; k < l; ++k) {
                    int p = 26;
                    if (s[k] >= 'a' && s[k] <= 'z')
                        p = s[k] - 'a';
                    if (!curr->children[p]) 
                        curr->children[p] = new TrieNode(i);
                    else
                        curr->children[p]->weight = i;
                    curr = curr->children[p];
                }
            }
        }
    }
    
    int f(const string& prefix, const string& suffix) {
        string psfix = suffix + '#' + prefix;
        TrieNode* curr = root;
        for (auto ch : psfix) {
            int p = 26;
            if (ch >= 'a' && ch <= 'z')
                p = ch - 'a';
            if (!curr->children[p])
                return -1;
            curr = curr->children[p];
        }
        return curr->weight;
    }
    
    ~WordFilter() {
        delete root;
    }
    
private:
    TrieNode* root;
};
