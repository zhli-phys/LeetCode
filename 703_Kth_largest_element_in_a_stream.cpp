class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k), count(0) {
        for (int num : nums) {
            pq.push({num, count});
            ++count;
            if (pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push({val, count});
        if (pq.size() > k)
            pq.pop();
        ++count;
        return pq.top().first;
    }
    
private: 
    int k;
    int count;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
};