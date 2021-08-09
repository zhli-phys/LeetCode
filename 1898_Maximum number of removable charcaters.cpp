//O(n^2) time limit exceeded
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size();
        int m = p.size();
        vector<int> pos(m);
        unordered_set<int> removed;
        for (int rem : removable)
            removed.insert(rem);
        int r = removable.size();
        for (int k = r; k > 0; --k) {
            int index = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == p[index] && removed.find(i) == removed.end()) {
                    pos[index] = i;
                    ++index;
                    if (index == m)
                        return k;
                }
            }
            removed.erase(removable[k-1]);
        }
        return 0;
    }
};














//binary search; O(n log n) 1712 ms 20%; 379.2 MB 20%
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int r = removable.size();
        return binary(0, r, s, p, removable);
    }
    
    int binary(int left, int right, const string& s, const string& p, vector<int>& removable) {
        if (left == right)
            return left;
        int mid = (left + right + 1) / 2;
        unordered_set<int> removed;
        for (int i = 0; i < mid; ++i)
            removed.insert(removable[i]);
        int index = 0;
        int n = s.size();
        int m = p.size();
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (removed.find(i) == removed.end() && s[i] == p[index]) {
                ++index;
                if (index == m) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            return binary(mid, right, s, p, removable);
        else
            return binary(left, mid - 1, s, p, removable);
    }
};













//binary search; O(n log n) 212 ms 40%; 92.3 MB 20%
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int r = removable.size();
        return binary(0, r, s, p, removable);
    }
    
    int binary(int left, int right, const string& s, const string& p, vector<int>& removable) {
        if (left == right)
            return left;
        int mid = (left + right + 1) / 2;
        string s_marked = s;
        for (int i = 0; i < mid; ++i)
            s_marked[removable[i]] = '-';
        int index = 0;
        int n = s.size();
        int m = p.size();
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (s_marked[i] == p[index]) {
                ++index;
                if (index == m) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            return binary(mid, right, s, p, removable);
        else
            return binary(left, mid - 1, s, p, removable);
    }
};