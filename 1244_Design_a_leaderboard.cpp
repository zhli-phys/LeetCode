class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (mp.find(playerId) != mp.end()) {
            --count[mp[playerId]];
            mp[playerId] += score;
            ++count[mp[playerId]];
        }
        else {
            mp[playerId] = score;
            ++count[score];
        }
    }
    
    int top(int K) {
        int ans = 0;
        int used = 0;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (used + it->second >= K) {
                ans += (K - used) * it->first;
                break;
            }
            else {
                ans += it->second * it->first;
                used += it->second;
            }
        }
        return ans;
    }
    
    void reset(int playerId) {
        --count[mp[playerId]];
        mp.erase(playerId);
    }
    
private:
    unordered_map<int, int> mp;
    map<int, int, greater<int>> count;
};



















struct Node {
    int val;
    Node* prev;
    Node* next;
    
    Node(int val) : val(val), prev(nullptr), next(nullptr) { }
};

class Leaderboard {
public:
    Leaderboard() {
        head = new Node(INT_MAX);
        tail = new Node(INT_MIN);
        head->next = tail;
        tail->prev = head;
    }
    
    void addScore(int playerId, int score) {
        if (mp.find(playerId) == mp.end()) {
            Node* target = new Node(score);
            mp[playerId] = target;
            auto curr = head;
            while (curr->next->val > score) 
                curr = curr->next;
            auto nxt = curr->next;
            curr->next = target;
            target->prev = curr;
            target->next = nxt;
            nxt->prev = target;
        }
        else {
            auto target = mp[playerId];
            target->val += score;
            auto curr = target->prev;
            while (curr->val < target->val)
                curr = curr->prev;
            if (curr != target->prev) {
                target->prev->next = target->next;
                target->next->prev = target->prev;
                auto nxt = curr->next;
                curr->next = target;
                target->prev = curr;
                target->next = nxt;
                nxt->prev = target;
            }
        }
    }
    
    int top(int K) {
        auto curr = head->next;
        int ans = 0;
        for (int i = 0; i < K; ++i) {
            ans += curr->val;
            curr = curr->next;
        }
        return ans;
    }
    
    void reset(int playerId) {
        auto target = mp[playerId];
        mp.erase(playerId);
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    
private:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
};