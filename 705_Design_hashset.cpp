struct MyListNode {
    int val;
    MyListNode* next;
    
    MyListNode(int val) : val(val), next(nullptr) { }
};

class MyList {
public:
    MyList() {
        head = new MyListNode(-1);
    }
    
    void insert(int val) {
        auto curr = head;
        while (curr->next) {
            curr = curr->next;
            if (curr->val == val)
                return;
        }
        curr->next = new MyListNode(val);
    }
    
    bool contains(int val) {
        auto curr = head->next;
        while (curr && curr->val != val)
            curr = curr->next;
        return curr;
    }
    
    void remove(int val) {
        auto curr = head;
        while (curr->next && curr->next->val != val)
            curr = curr->next;
        if (curr->next)
            curr->next = curr->next->next;
    }
    
private:
    MyListNode* head;
};

class MyHashSet {
public:
    MyHashSet() : p(997), vec(p) {
        
    }
    
    void add(int key) {
        vec[key % p].insert(key);
    }
    
    void remove(int key) {
        vec[key % p].remove(key);
    }
    
    bool contains(int key) {
        return vec[key % p].contains(key);
    }
    
private:
    int p;
    vector<MyList> vec;
};























struct MyListNode {
    int val;
    MyListNode* next;
    
    MyListNode(int val) : val(val), next(nullptr) { }
};

class MyList {
public:
    MyList() : head(nullptr) { }
    
    void insert(int val) {
        if (!head)
            head = new MyListNode(val);
        else {
            auto curr = head;
            if (curr->val == val)
                return;
            while (curr->next) {
                curr = curr->next;
                if (curr->val == val)
                    return;
            }
            curr->next = new MyListNode(val);
        }
    }
    
    bool contains(int val) {
        auto curr = head;
        while (curr && curr->val != val)
            curr = curr->next;
        return curr;
    }
    
    void remove(int val) {
        if (!head)
            return; 
        else if (head->val == val)
            head = head->next;
        else {
            auto curr = head;
            while (curr->next && curr->next->val != val)
                curr = curr->next;
            if (curr->next)
                curr->next = curr->next->next;
        }
    }
    
private:
    MyListNode* head;
};

class MyHashSet {
public:
    MyHashSet() : p(997), vec(p) {
        
    }
    
    void add(int key) {
        vec[key % p].insert(key);
    }
    
    void remove(int key) {
        vec[key % p].remove(key);
    }
    
    bool contains(int key) {
        return vec[key % p].contains(key);
    }
    
private:
    int p;
    vector<MyList> vec;
};