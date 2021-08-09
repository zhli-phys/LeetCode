//list; O(n^2) 160 ms 17%; 27.6 MB 13%
class MyCalendarThree {
public:
    MyCalendarThree() : k(0) {
        
    }
    
    int book(int start, int end) {
        k = max(k, 1);
        auto it = slots.begin();
        while (it != slots.end() && (*it)[1] <= start)
            ++it;
        if (it == slots.end() || (*it)[0] >= end)
            slots.insert(it, {start, end, 1});
        else {
            if ((*it)[0] < start) {
                slots.insert(it, {(*it)[0], start, (*it)[2]});
                (*it)[0] = start;
            }
            while (it != slots.end() && (*it)[1] <= end) {
                if ((*it)[0] > start) 
                    slots.insert(it, {start, (*it)[0], 1});
                ++((*it)[2]);
                start = (*it)[1];
                k = max(k, (*it)[2]);
                ++it;
            }
            if (start < end) {
                if (it == slots.end() || (*it)[0] >= end)
                    slots.insert(it, {start, end, 1});
                else {
                    if ((*it)[0] > start) 
                        slots.insert(it, {start, (*it)[0], 1});
                    slots.insert(it, {(*it)[0], end, (*it)[2] + 1});
                    k = max(k, (*it)[2] + 1);
                    (*it)[0] = end;
                }
            }
        }
        return k;
    }
    
private:
    int k;
    list<vector<int>> slots;
};

















//boundary count; O(n^2) 148 ms 19%; 26.3 MB 62%
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++delta[start];
        --delta[end];
        int k = 0;
        int curr = 0;
        for (auto it = delta.begin(); it != delta.end(); ++it) {
            curr += it->second;
            k = max(k, curr);
        }
        return k;
    }
    
private:
    map<int, int> delta;
};

















//boundary count; O(n^2) 148 ms 19%; 26.3 MB 62%
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++delta[start];
        --delta[end];
        int k = 0;
        int curr = 0;
        for (auto&& p : delta) {
            curr += p.second;
            k = max(k, curr);
        }
        return k;
    }
    
private:
    map<int, int> delta;
};