using ll = long long;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target[0] == 1;
        ll sum = accumulate(target.begin(), target.end(), 0ll);
        priority_queue<ll> pq;
        for (int num : target)
            pq.push(num);
        while (!pq.empty() && pq.top() != 1) {
            ll curr = pq.top();
            ll others = sum - curr;
            if (others == 1)
                return true;
            if (curr <= others)
                return false;
            ll next = curr % others;
            if (next == 0)
                return false;
            sum -= (curr - next);
            pq.pop();
            pq.push(next);
        }
        return true;
    }
};