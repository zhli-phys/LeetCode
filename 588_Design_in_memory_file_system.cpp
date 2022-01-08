struct fileNode {
    string name;
    string content;
    bool isDir;
    map<string, fileNode*> mp;
    
    fileNode(const string& name, bool isDir = true) : name(name), isDir(isDir) { }
};

class FileSystem {
public:
    FileSystem() {
        root = new fileNode("/");
    }
    
    vector<string> ls(string path) {
        vector<string> dir = split(path);
        auto curr = root;
        for (auto& d : dir) {
            if (curr->mp.find(d) == curr->mp.end())
                return {};
            curr = curr->mp[d];
        }
        if (!curr->isDir)
            return {curr->name};
        vector<string> ans;
        for (auto& child : curr->mp)
            ans.push_back(child.first);
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> dir = split(path);
        auto curr = root;
        for (auto& d : dir) {
            if (curr->mp.find(d) == curr->mp.end())
                curr->mp[d] = new fileNode(d);
            curr = curr->mp[d];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto dir = split(filePath);
        auto curr = root;
        for (auto& d : dir) {
            if (curr->mp.find(d) == curr->mp.end())
                curr->mp[d] = new fileNode(d);
            curr = curr->mp[d];
        }
        curr->isDir = false;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto dir = split(filePath);
        auto curr = root;
        for (auto& d : dir) {
            if (curr->mp.find(d) == curr->mp.end())
                return "";
            curr = curr->mp[d];
        }
        return curr->content;
    }
    
    vector<string> split(const string& path, char ch = '/') {
        int i = 0; 
        int n = path.size();
        vector<string> ans;
        while (i < n - 1) {
            if (path[i] == ch) {
                ++i;
                string curr;
                while (i < n && path[i] != ch) {
                    curr += path[i];
                    ++i;
                }                    
                ans.push_back(curr);
            }
            else 
                return {};
        }
        return ans;
    }
    
private:
    fileNode* root;
};