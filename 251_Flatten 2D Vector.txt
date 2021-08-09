class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        it1 = v.begin();
        myend = v.end();
        if (it1 != myend)
            it2 = it1->begin();
    }
    
    int next() {
        if (it2 != it1->end()) {
            int temp = *it2;
            it2++;
            return temp;
        }
        else {
            it1++;
            it2 = it1->begin();
            int temp = *it2;
            it2++;
            return temp;
        }
    }
    
    bool hasNext() {
        while (it1 != myend && it2 == it1->end()) {
            it1++;
            if (it1 != myend)
                it2 = it1->begin();
        }
        return (it1 != myend);
    }
    
private:
    vector<vector<int>>::iterator it1;
    vector<vector<int>>::iterator myend;
    vector<int>::iterator it2;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */