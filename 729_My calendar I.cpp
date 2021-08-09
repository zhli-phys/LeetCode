//use linked list; O(n^2) 100 ms 42%; O(n) 38.3 MB 80%
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = slots.begin();
        while (it != slots.end() && it->second <= start)
            ++it;
        if (it != slots.end() && it->first < end)
            return false;
        slots.insert(it, {start, end});
        return true;
    }
    
private:
    list<pair<int, int>> slots;
};










//use set; O(n log n) 80 ms 79%; O(n) 38.7 MB 74%
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> curr{start, end};
        auto it = slots.lower_bound(curr);
        if (it != slots.end() && it->first < end)
            return false;
        if (it != slots.begin() && (--it)->second > start)
            return false;
        slots.insert(curr);
        return true;
    }
    
private:
    set<pair<int, int>> slots;
};