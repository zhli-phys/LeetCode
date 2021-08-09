struct TrieNode {
    vector<TrieNode*> children;
    int count = 0;
    TrieNode() : children(2, NULL), count(0) { }
};

class Trie {
public:
    Trie(int N) : N(N) {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = N - 1; i >= 0; --i) {
            int bit = (num >> i) % 2;
            if (!curr->children[bit])
                curr->children[bit] = new TrieNode();
            curr = curr->children[bit];
            ++curr->count;
        }
    }
    
    void erase(int num) {
        TrieNode* curr = root;
        for (int i = N - 1; i >= 0; --i) {
            int bit = (num >> i) % 2;
            curr = curr->children[bit];
            --curr->count;
        }
    }
    
    int max_diff(int val) {
        int ans = 0;
        TrieNode* curr = root;
        for (int i = N - 1; i >= 0; --i) {
            int bit = (val >> i) % 2;
            ans *= 2;
            if (curr->children[!bit] && curr->children[!bit]->count > 0) {
                curr = curr->children[!bit];
                ans += 1;
            }
            else
                curr = curr->children[bit];
        }
        return ans;
    }
private:
    TrieNode* root;
    int N;
};

class Solution {
public:
    const int N = int(log2(2e5)) + 1;
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        vector<vector<int>> edges(n);
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parents[i] == -1)
                root = i;
            else
                edges[parents[i]].push_back(i);
        }
        int m = queries.size();
        vector<vector<int>> quests(n);
        for (int i = 0; i < m; ++i) 
            quests[queries[i][0]].push_back(i);
        
        Trie trie(N);
        vector<int> ans(m);
        dfs(root, trie, edges, quests, queries, ans);
        return ans;
    }
    
    void dfs(int num, Trie& trie, vector<vector<int>>& edges, vector<vector<int>>& quests, vector<vector<int>>& queries, vector<int>& ans) {
        trie.insert(num);
        for (int i : quests[num]) {
            int val = queries[i][1];
            ans[i] = trie.max_diff(val);
        }
        for (int edge : edges[num]) 
            dfs(edge, trie, edges, quests, queries, ans);
        trie.erase(num);
    }
};