class DSU {
public:
    DSU (int n) {
        vector<int> head(n);
        for (int i = 0; i < n; i++)
            head[i] = i;
    }
    
    int find(int i) {
        if (head[i] != i)
            head[i] = find(head[i]);
        return head[i];
    }
    
    void unite(int i, int j) {
        head[find(i)] = find(j);
    }
    
private:
    vector<int> head;
};






///////////////////////////////////////////////////////////
int find(unordered_map<int, int>& dsu, int x) {
    if (dsu.find(x) == dsu.end() || dsu[x] == x)
        dsu[x] = x;
    else
        dsu[x] = find(dsu, dsu[x]);
    return dsu[x];
}

void unite(unordered_map<int, int>& dsu, int x, int y) {
    dsu[find(dsu, x)] = find(dsu, y);
}