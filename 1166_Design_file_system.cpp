struct Node {
    int val;
    unordered_map<string, Node*> children;
    
    Node(int val) : val(val) { }
};

class FileSystem {
public:
    FileSystem() {
        root = new Node(-1);
    }
    
    bool createPath(string path, int value) {
        auto dirs = split(path, '/');
        int n = dirs.size();
        auto curr = root;
        for (int i = 1; i < n - 1; ++i) {
            auto& dir = dirs[i];
            if (curr->children.find(dir) == curr->children.end())
                return false;
            curr = curr->children[dir];
        }
        auto& last = dirs.back();
        if (curr->children.find(last) != curr->children.end())
            return false;
        curr->children[last] = new Node(value);
        return true;
    }
    
    int get(string path) {
        auto dirs = split(path, '/');
        int n = dirs.size();
        auto curr = root;
        for (int i = 1; i < n; ++i) {
            auto& dir = dirs[i];
            if (curr->children.find(dir) == curr->children.end())
                return -1;
            curr = curr->children[dir];
        }
        return curr->val;
    }
    
    vector<string> split(const string& s, char d = ' ') {
        vector<string> ans;
        string curr;
        for (char ch : s) {
            if (ch == d) {
                ans.push_back(curr);
                curr = "";
            }
            else 
                curr.push_back(ch);
        }
        ans.push_back(curr);
        return ans;
    }
    
private:
    Node* root;
};