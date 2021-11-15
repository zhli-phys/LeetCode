class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) 
        : str(characters), n(combinationLength), index(n, -1) {

    }
    
    string next() {
        string ans;
        if (index[0] == -1) {
            for (int i = 0; i < n; ++i)
                index[i] = i;
        }            
        else {
            for (int i = n - 1; i >= 0; --i) {
                if (index[i] < str.size() - n + i) {
                    ++index[i];
                    for (int j = i + 1; j < n; ++j)
                        index[j] = index[j-1] + 1;
                    break;
                }
            }
        }        
        for (int num : index)
            ans += str[num];        
        return ans;
    }
    
    bool hasNext() {
        return index[0] != str.size() - n;
    }
    
private:
    string str;
    int n;
    vector<int> index;
};
