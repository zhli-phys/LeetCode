class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        string s = to_string(N);
        int n = s.size();
        unordered_set<int> visited;
        int ans = 0;
        for (int i = 1; i < 10; i++)
            ans += helper(i, 0, s, visited);
        for (int i = 1; i < n; i++) 
            ans += 9 * (powten(i-1) - f(i-1, 9));
        return ans;
    }
    
    int helper(int i, int pos, string& s, unordered_set<int>& visited) {
        int n = s.size();
        if (pos >= n || i > s[pos]-'0')
            return 0;
        if (i < s[pos]-'0') {
            if (visited.count(i))
                return powten(n-pos-1);
            else 
                return powten(n-pos-1) - f(n-pos-1, 9-visited.size());
        }
        else {
            if (visited.count(i)) {
                if (pos < n-1)
                    return stoi(s.substr(pos+1))+1;
                else
                    return 1;
            }
            else {
                visited.insert(i);
                int ans = 0;
                for (int j = 0; j < 10; j++) 
                    ans += helper(j, pos+1, s, visited);
                return ans;
            }
        }
    }
    
    int powten(int n) {
        return floor(pow(10, n) + 0.5);
    }
    
    int f(int n, int m) { // m*(m-1)*(m-2)*...*(m-n+1)
        if (n > m)
            return 0;
        int ans = 1;
        for (int i = 0; i < n; i++) 
            ans *= (m-i);
        return ans;
    }
};