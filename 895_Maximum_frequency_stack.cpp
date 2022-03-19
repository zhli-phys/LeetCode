class FreqStack {
public:
    FreqStack() : vec(1) {
        
    }
    
    void push(int val) {
        ++freq[val];
        if (vec.size() < freq[val] + 1) 
            vec.push_back({val});
        else
            vec[freq[val]].push_back(val);
    }
    
    int pop() {
        int ans = vec.back().back();
        --freq[ans];
        vec.back().pop_back();
        if (vec.back().empty())
            vec.pop_back();
        return ans;
    }
    
private:
    unordered_map<int, int> freq;
    vector<vector<int>> vec;
};













class FreqStack {
public:
    FreqStack() : index(0) {
        
    }
    
    void push(int val) {
        auto& v = pos[val];
        if (!v.empty()) 
            st.erase({v.size(), {v.back(), val}});
        v.push_back(index);
        st.insert({v.size(), {v.back(), val}});
        ++index;
    }
    
    int pop() {
        auto it = st.begin();
        int ans = it->second.second;
        st.erase(it);
        auto& v = pos[ans];
        v.pop_back();
        if (!v.empty())
            st.insert({v.size(), {v.back(), ans}});
        return ans;
    }
    
private:
    unordered_map<int, vector<int>> pos;
    set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> st;
    int index;
};