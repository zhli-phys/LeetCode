class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        return isHappy(n, visited);
    }
    
    bool isHappy(int n, unordered_set<int>& visited) {
        if (n == 1)
            return true;
        if (visited.count(n))
            return false;
        visited.insert(n);
        int next = 0;
        while (n != 0) {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(next, visited);
    }
};