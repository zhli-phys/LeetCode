struct MyListNode {
    int key;
    int val;
    MyListNode* next;
    
    MyListNode(int key, int val) : key(key), val(val), next(nullptr) { }
};

class MyList {
public:
    MyList() {
        head = new MyListNode(-1, -1);
    }
    
    void insert(int key, int val) {
        auto curr = head;
        while (curr->next) {
            curr = curr->next;
            if (curr->key == key) {
                curr->val = val;
                return;
            }
        }            
        curr->next = new MyListNode(key, val);
    }
    
    int get(int key) {
        auto curr = head->next;
        while (curr && curr->key != key)
            curr = curr->next;
        if (curr)
            return curr->val;
        else
            return -1;
    }
    
    void remove(int key) {
        auto curr = head;
        while (curr->next && curr->next->key != key)
            curr = curr->next;
        if (curr->next)
            curr->next = curr->next->next;
    }
    
private:
    MyListNode* head;
};

class MyHashMap {
public:
    MyHashMap() : p(997), vec(p) {
        
    }
    
    void put(int key, int value) {
        vec[key % p].insert(key, value);
    }
    
    int get(int key) {
        return vec[key % p].get(key);
    }
    
    void remove(int key) {
        vec[key % p].remove(key);
    }
    
private:
    int p;
    vector<MyList> vec;
};