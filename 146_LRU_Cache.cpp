//using queue
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            keys.push(key);
            ++mp[key].second;
            return mp[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        mp[key].first = value;
        keys.push(key);
        ++mp[key].second;
        if (mp.size() > capacity) {
            while (true) {
                int luk = keys.front();
                keys.pop();
                --mp[luk].second;
                if (mp[luk].second == 0) {
                    mp.erase(luk);
                    break;
                }
            }
        }
    }
    
private:
    queue<int> keys;
    int capacity;
    unordered_map<int, pair<int, int>> mp;
};














//using linked list
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second = keys.begin();
            return mp[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) 
            keys.erase(mp[key].second);
        else if (mp.size() == capacity) {
            mp.erase(keys.back());
            keys.pop_back();
        }
        keys.push_front(key);
        mp[key] = {value, keys.begin()};
    }
    
private:
    int capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
};




















class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {

    }

    int get(int key) {
        unordered_map<int, int>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            if (temp == InnerList.front()) {
                return temp->second;
            }
            InnerList.remove(temp);
            InnerList.push_front(temp);
            return temp->second;
        }
        return -1;
    }

    void put(int key, int value) {
        unordered_map<int, int>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            temp->second = value;
            if (temp != InnerList.front()) {
                InnerList.remove(temp);
                InnerList.push_front(temp);
            }
        }
        else {
            if (size < capacity) {
                InnerCache.insert(pair<int, int>(key, value));
                temp = InnerCache.find(key);
                InnerList.push_front(temp);
                size++;
            }
            else {
                temp = InnerList.back();
                InnerList.pop_back();
                InnerCache.erase(temp);
                InnerCache.insert(pair<int, int>(key, value));
                temp = InnerCache.find(key);
                InnerList.push_front(temp);
            }
        }
    }

private:
    unordered_map<int, int> InnerCache;
    list<unordered_map<int, int>::iterator> InnerList;
    int capacity;
    int size;
};













class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {

    }

    int get(int key) {
        unordered_map<int, MyStruct>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            if (key != InnerQueue.back()) {
                InnerQueue.push(key);
                temp->second.count++;
            }
            return temp->second.value;
        }
        return -1;
    }

    void put(int key, int value) {
        unordered_map<int, MyStruct>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            temp->second.value = value;
            if (key != InnerQueue.back()) {
                InnerQueue.push(key);
                temp->second.count++;
            }
        }
        else {
            if (size < capacity) {
                InnerCache.insert(pair<int, MyStruct>(key, MyStruct(value)));
                InnerQueue.push(key);
                size++;
            }
            else {
                while (true) {
                    int front = InnerQueue.front();
                    InnerQueue.pop();
                    temp = InnerCache.find(front);
                    temp->second.count--;
                    if (temp->second.count == 0) {
                        InnerCache.erase(temp);
                        break;
                    }
                }
                InnerCache.insert(pair<int, MyStruct>(key, MyStruct(value)));
                InnerQueue.push(key);
            }
        }
    }

private:
    struct MyStruct
    {
        int count;
        int value;
        MyStruct(int value, int count=1) : value(value), count(count) {}
    };
    unordered_map<int, MyStruct> InnerCache;
    queue<int> InnerQueue;
    int capacity;
    int size;
};











class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {

    }

    int get(int key) {
        unordered_map<int, Node*>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            if (temp->second != front) {
                if (temp->second == back) {
                    temp->second->prev->next = NULL;
                    back = temp->second->prev;
                }
                else {
                    temp->second->prev->next = temp->second->next;
                    temp->second->next->prev = temp->second->prev;
                }
                temp->second->next = front;
                front->prev = temp->second;
                temp->second->prev = NULL;
                front = temp->second;
            }
            return temp->second->value;
        }
        return -1;
    }

    void put(int key, int value) {
        unordered_map<int, Node*>::iterator temp = InnerCache.find(key);
        if (temp != InnerCache.end()) {
            temp->second->value = value;
            if (temp->second != front) {
                temp->second->prev->next = temp->second->next;
                if (temp->second == back) {
                    back = temp->second->prev;
                }
                else {
                    temp->second->next->prev = temp->second->prev;
                }
                temp->second->next = front;
                front->prev = temp->second;
                temp->second->prev = NULL;
                front = temp->second;
            }
        }
        else {
            if (size == 0) {
                Node* newnode = new Node(key, value);
                front = newnode;
                back = newnode;
                InnerCache.insert(pair<int, Node*>(key, newnode));
                size++;
            }
            else {
                if (size < capacity) {
                    Node* newnode = new Node(key, value);
                    newnode->next = front;
                    front->prev = newnode;
                    front = newnode;
                    InnerCache.insert(pair<int, Node*>(key, newnode));
                    size++;
                }
                else {
                    InnerCache.erase(back->key);
                    if (size == 1) {
                        Node* newnode = new Node(key, value);
                        front = newnode;
                        back = newnode;
                        InnerCache.insert(pair<int, Node*>(key, newnode));
                    }
                    else {
                        back->prev->next = NULL;
                        back = back->prev;
                        Node* newnode = new Node(key, value);
                        newnode->next = front;
                        front->prev = newnode;
                        front = newnode;
                        InnerCache.insert(pair<int, Node*>(key, newnode));
                    }
                }
            }
        }
    }

private:
    struct Node
    {
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
    };
    unordered_map<int, Node*> InnerCache;
    int capacity;
    int size;
    Node* front;
    Node* back;
};
















class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            keys.push(key);
            counts[key]++;
            return mp[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        mp[key] = value;
        keys.push(key);
        ++counts[key];
        if (mp.size() > capacity) {
            while (true) {
                int luk = keys.front();
                keys.pop();
                --counts[luk];
                if (counts[luk] == 0) {
                    counts.erase(luk);
                    mp.erase(luk);
                    break;
                }
            }
        }
    }
    
private:
    queue<int> keys;
    int capacity;
    unordered_map<int, int> mp;
    unordered_map<int, int> counts;
};