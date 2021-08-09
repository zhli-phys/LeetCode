struct node {
        bool contained;
        node* next[26];
        node(bool contained = false): contained(contained) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    ~Trie() {
        remove(root);
    }
    
    void remove(node* root) {
        if (!root)
            return;
        for (int i = 0; i < 26; i++)
            remove(root->next[i]);
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                current->next[word[i] - 97] = new node();
            current = current->next[word[i] - 97];
        }
        current->contained = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return false;
            current = current->next[word[i] - 97];
        }
        return current->contained;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[prefix[i] - 97])
                return false;
            current = current->next[prefix[i] - 97];
        }
        return true;
    }
    
private:
    node* root;
};











//Time limit exceeded
struct node {
        bool contained;
        node* next[26];
        node(bool contained = false): contained(contained) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    ~Trie() {
        remove(root);
    }
    
    void remove(node* root) {
        if (!root)
            return;
        for (int i = 0; i < 26; i++)
            remove(root->next[i]);
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                current->next[word[i] - 97] = new node();
            current = current->next[word[i] - 97];
        }
        current->contained = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return false;
            current = current->next[word[i] - 97];
        }
        return current->contained;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[prefix[i] - 97])
                return false;
            current = current->next[prefix[i] - 97];
        }
        return true;
    }
    
private:
    node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int len = words.size();
        Trie wordset;
        for (int i = 0; i < len; i++) 
            wordset.insert(words[i]);
        int n = board.size();
        int m = board[0].size();
        unordered_map<int, unordered_set<int>> visited;
        string current = "";
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                explore(board, wordset, i, j, current, visited, ans);
        }
        vector<string> sol;
        for (unordered_set<string>::iterator it = ans.begin(); it != ans.end(); it++)
            sol.push_back(*it);
        return sol;
    }
    
    void explore(vector<vector<char>>& board, Trie& wordset, int i, int j, string current, 
         unordered_map<int, unordered_set<int>> visited, unordered_set<string>& ans) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        unordered_map<int, unordered_set<int>>::iterator it = visited.find(i);
        if (it != visited.end() && it->second.find(j) != it->second.end())
            return;
        visited[i].insert(j);
        current += board[i][j];
        if (!wordset.startsWith(current))
            return;
        if (wordset.search(current)) 
            ans.insert(current);
        explore(board, wordset, i - 1, j, current, visited, ans);
        explore(board, wordset, i + 1, j, current, visited, ans);
        explore(board, wordset, i, j - 1, current, visited, ans);
        explore(board, wordset, i, j + 1, current, visited, ans);
    }
};




struct node {
        bool contained;
        node* next[26];
        node(bool contained = false): contained(contained) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node(true);
    }
    
    ~Trie() {
        remove(root);
    }
    
    void remove(node* root) {
        if (!root)
            return;
        for (int i = 0; i < 26; i++)
            remove(root->next[i]);
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                current->next[word[i] - 97] = new node();
            current = current->next[word[i] - 97];
        }
        current->contained = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return false;
            current = current->next[word[i] - 97];
        }
        return current->contained;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[prefix[i] - 97])
                return false;
            current = current->next[prefix[i] - 97];
        }
        return true;
    }
    
    void erase(string word) {
        int len = word.size();
        node* current = root;
        stack<node*> path;
        stack<int> indices;
        path.push(root);
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return;
            current = current->next[word[i] - 97];
            path.push(current);
            indices.push(word[i] - 97);
        }
        current->contained = false; 
        node* prev;
        while (true) {
            current = path.top();
            if (current->contained)
                break;
            path.pop();
            int temp = indices.top();
            indices.pop();
            prev = path.top();
            bool nochild = true;
            for (int i = 0; i < 26; i++)
                if (current->next[i]) {
                    nochild = false;
                    break;
                }
            if (nochild) {
                prev->next[temp] = NULL;
                delete current;
            }
            else
                break;
        }
    }
    
private:
    node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int len = words.size();
        Trie wordset;
        for (int i = 0; i < len; i++) 
            wordset.insert(words[i]);
        int n = board.size();
        int m = board[0].size();
        unordered_map<int, unordered_set<int>> visited;
        string current = "";
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                explore(board, wordset, i, j, current, visited, ans);
        }
        vector<string> sol;
        for (unordered_set<string>::iterator it = ans.begin(); it != ans.end(); it++)
            sol.push_back(*it);
        return sol;
    }
    
    void explore(vector<vector<char>>& board, Trie& wordset, int i, int j, string current, 
         unordered_map<int, unordered_set<int>>& visited, unordered_set<string>& ans) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        unordered_map<int, unordered_set<int>>::iterator it = visited.find(i);
        if (it != visited.end() && it->second.find(j) != it->second.end())
            return;
        current += board[i][j];
        if (!wordset.startsWith(current)) 
            return;
        visited[i].insert(j);
        if (wordset.search(current)) {
            wordset.erase(current);
            ans.insert(current);
        }
        explore(board, wordset, i - 1, j, current, visited, ans);
        explore(board, wordset, i + 1, j, current, visited, ans);
        explore(board, wordset, i, j - 1, current, visited, ans);
        explore(board, wordset, i, j + 1, current, visited, ans);
        visited[i].erase(j);
    }
};






struct node {
        bool contained;
        node* next[26];
        node(bool contained = false): contained(contained) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node(true);
    }
    
    ~Trie() {
        remove(root);
    }
    
    void remove(node* root) {
        if (!root)
            return;
        for (int i = 0; i < 26; i++)
            remove(root->next[i]);
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                current->next[word[i] - 97] = new node();
            current = current->next[word[i] - 97];
        }
        current->contained = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return false;
            current = current->next[word[i] - 97];
        }
        return current->contained;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        node* current = root;
        for (int i = 0; i < len; i++) {
            if (!current->next[prefix[i] - 97])
                return false;
            current = current->next[prefix[i] - 97];
        }
        return true;
    }
    
    void erase(string word) {
        int len = word.size();
        node* current = root;
        stack<node*> path;
        stack<int> indices;
        path.push(root);
        for (int i = 0; i < len; i++) {
            if (!current->next[word[i] - 97])
                return;
            current = current->next[word[i] - 97];
            path.push(current);
            indices.push(word[i] - 97);
        }
        current->contained = false; 
        node* prev;
        while (true) {
            current = path.top();
            if (current->contained)
                break;
            path.pop();
            int temp = indices.top();
            indices.pop();
            prev = path.top();
            bool nochild = true;
            for (int i = 0; i < 26; i++)
                if (current->next[i]) {
                    nochild = false;
                    break;
                }
            if (nochild) {
                prev->next[temp] = NULL;
                delete current;
            }
            else
                break;
        }
    }
    
private:
    node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int len = words.size();
        Trie wordset;
        for (int i = 0; i < len; i++) 
            wordset.insert(words[i]);
        int n = board.size();
        int m = board[0].size();
        vector<bool> row(m, false);
        vector<vector<bool>> visited(n, row);
        string current = "";
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                explore(board, wordset, i, j, current, visited, ans);
        }
        vector<string> sol;
        for (unordered_set<string>::iterator it = ans.begin(); it != ans.end(); it++)
            sol.push_back(*it);
        return sol;
    }
    
    void explore(vector<vector<char>>& board, Trie& wordset, int i, int j, string current, 
         vector<vector<bool>>& visited, unordered_set<string>& ans) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visited[i][j])
            return;
        current += board[i][j];
        if (!wordset.startsWith(current)) 
            return;
        visited[i][j] = true;
        if (wordset.search(current)) {
            wordset.erase(current);
            ans.insert(current);
        }
        explore(board, wordset, i - 1, j, current, visited, ans);
        explore(board, wordset, i + 1, j, current, visited, ans);
        explore(board, wordset, i, j - 1, current, visited, ans);
        explore(board, wordset, i, j + 1, current, visited, ans);
        visited[i][j] = false;
    }
};