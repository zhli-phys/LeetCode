class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> wordset;
        for (auto& word : words)
            wordset.insert(word);
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        string curr;
        vector<string> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, curr, board, wordset, visited, ans);
            }
        }
        return ans;
    }
    
    void dfs(int i, int j, string& curr, vector<vector<char>>& board, unordered_set<string>& wordset,
             vector<vector<bool>>& visited, vector<string>& ans) {
        int m = board.size();
        int n = board[0].size();
        if (curr.size() >= 10 || i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return;
        curr.push_back(board[i][j]);
        visited[i][j] = true;
        if (wordset.find(curr) != wordset.end()) {
            ans.push_back(curr);
            wordset.erase(curr);
        }
        for (int k = 0; k < 4; ++k)
            dfs(i + dir[k][0], j + dir[k][1], curr, board, wordset, visited, ans);
        visited[i][j] = false;
        curr.pop_back();
    }
};









//Time limit exceeded
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char, unordered_map<int, unordered_set<int>>> pos;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                pos[board[i][j]][i].insert(j);
        vector<string> ans;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            unordered_map<char, unordered_map<int, unordered_set<int>>>::iterator it = pos.find(words[i][0]);
            if (it != pos.end()) {
                for (unordered_map<int, unordered_set<int>>::iterator it2 = it->second.begin(); 
                     it2 != it->second.end(); it2++) {
                    bool gotit = false;
                    for (unordered_set<int>::iterator it3 = it2->second.begin(); it3 != it2->second.end(); it3++) {
                            unordered_map<int, unordered_set<int>> prev;
                        if (found(board, words[i], it2->first, *it3, 0, prev)) {
                            ans.push_back(words[i]);
                            gotit = true;
                            break;
                        }
                    }
                    if (gotit)
                        break;
                }
            }
        }
        return ans;
    }
    
    bool found(vector<vector<char>>& board, string& word, int i, int j, int start, 
               unordered_map<int, unordered_set<int>> prev) {
        if (board[i][j] != word[start])
            return false;
        if (start == word.size() - 1)
            return true;
        prev[i].insert(j);
        int n = board.size();
        int m = board[0].size();
        unordered_map<int, unordered_set<int>>::iterator it = prev.find(i);
        if (j > 0 && it->second.find(j - 1) == it->second.end() && found(board, word, i, j - 1, start + 1, prev))
            return true;
        if (j < m - 1 && it->second.find(j + 1) == it->second.end() && found(board, word, i, j + 1, start + 1, prev))
            return true;
        if (i > 0) {
            it = prev.find(i - 1);
            if ((it == prev.end() || it->second.find(j) == it->second.end()) 
                && found(board, word, i - 1, j, start + 1, prev))
                return true;
        }
        if (i < n - 1) {
            it = prev.find(i + 1);
            if ((it == prev.end() || it->second.find(j) == it->second.end()) 
                && found(board, word, i + 1, j, start + 1, prev))
                return true;
        }
        return false;
    }
};





\\Time limit exceeded
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
        if (wordset.search(current)) {
            wordset.erase(current);
            ans.insert(current);
        }
        explore(board, wordset, i - 1, j, current, visited, ans);
        explore(board, wordset, i + 1, j, current, visited, ans);
        explore(board, wordset, i, j - 1, current, visited, ans);
        explore(board, wordset, i, j + 1, current, visited, ans);
    }
};